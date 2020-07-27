#ifndef THREAD_POOL_H_
#define THREAD_POOL_H_
#include <condition_variable>
#include <mutex>
#include <future>
#include <queue>
#include <functional>
#include <thread>
#include <vector>
#include <memory>

class ThreadPool {
public:
    static ThreadPool* GetInstance();
    template<class F, class... Args>
    auto Execute(F&& f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type>;
    ~ThreadPool();
    void StopThreadPool(bool flag)
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_runStatus = flag;
    }
    
    ThreadPool() = delete;
    ThreadPool(const ThreadPool&) = delete;
    ThreadPool& operator=(const ThreadPool&) = delete;
    ThreadPool(const ThreadPool&&) = delete;
    ThreadPool& operator=(const ThreadPool&&) = delete;

private:
    ThreadPool(unsigned int size);
    static ThreadPool* instance;
    static std::once_flag m_flag;
    static void InitInstance()
    {
        instance = new ThreadPool(5);
    }

private:
    bool m_runStatus;
    std::mutex m_mutex;
    std::condition_variable m_conv;
    std::queue<std::function<void()>> m_tasks;
    std::vector<std::thread> m_threads;

};
/*
ThreadPool* ThreadPool::GetInstance()
{
    std::call_once(m_flag, InitInstance);
    return instance;
}

ThreadPool::ThreadPool(unsigned int size) : m_runStatus(false)
{
    for (int i = 0; i < size; ++i) {
        m_threads.emplace_back([this](){
            for(;;) {
                std::unique_lock<std::mutex> lock(m_mutex);
                this->m_conv.wait(lock, [this](){ return this->m_runStatus || !this->m_tasks.empty();});
                if (this->m_runStatus) {
                    break;
                }

                auto task = this->m_tasks.front();
                this->m_tasks.pop();
                task();
            }
        });
    }
}

template<class F, class... Args>
auto ThreadPool::Execute(F&& f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type>
{
    using returnType = std::future<typename std::result_of<F(Args...)>::type>;
    auto task = std::shared_ptr<std::packaged_task<returnType()>>(std::bind(f, args));
    returnType res = task->get_future();
    if (m_runStatus) {
        throw "thread is stop";
    } else {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_tasks.emplace([&task](){(*task)()});
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
    for (auto& iter : m_threads) {
        if (iter.joinable()) {
            iter.join();
        }
    }
}
*/

#endif