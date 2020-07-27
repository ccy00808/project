#include "threadpool.h"

ThreadPool* ThreadPool::GetInstance()
{
    std::call_once(m_flag, InitInstance);
    return instance;
}

ThreadPool::ThreadPool(unsigned int size) : m_runStatus(false)
{
    for (int i = 0; i < size; ++i) {
        m_threads.emplace_back([this](){
            for (;;) {
                std::unique_lock<std::mutex> lock(this->m_mutex);
                this->m_conv.wait(lock, [this](){return this->m_runStatus || !this->m_tasks.empty();});
                if (this->m_runStatus) {
                    return;
                } else {
                    auto task = this->m_tasks.front();
                    this->m_tasks.pop();
                    task();
                }
            }
        });
    }
}

template<class F, class... Args>
auto ThreadPool::Execute(F&& f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type>
{
    using ReturnType = std::future<typename std::result_of<F(Args...)>::type>;
    auto task = std::share_ptr<std::package_task<ReturnType()>>(std::bind(f, args));
    ReturnType res = task->get_future();
    if (m_runStatus) {
        throw "threadpool stop";
    } else {
        std::unique<std::mutex> lock(m_mutex);
        m_tasks.emplace([task](){(*task)()});
    }
    m_conv.notify_one();
    return res;
}

ThreadPool::~ThreadPool()
{
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_runStatus = true;
    }
    for(auto& iter : m_threads) {
        if (iter.joinable()) {
            iter.join();
        }
    }
}