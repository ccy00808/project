#include "multhread.h"
#include <atomic>
#include <vector>
#include <condition_variable>
#include <mutex>
#include <iostream>
#include <unistd.h>
#include <map>
#include <string>
#include "rwlock.h"
#include <exception>
#include <future>
#include <chrono>

std::atomic<int> g_golbalint(0);
std::vector<int> g_golbalves(0);
std::map<int, std::string> maps;

std::mutex ml;
std::condition_variable m_rconv;
std::condition_variable m_wconv;

RWLock rw;

void ThreadFunc1()
{
    int cout = 0;
    while (true) {
        g_golbalint++;
        {
            std::lock_guard<std::mutex> lk1(ml);
            long long result = 0;
            for (auto it : g_golbalves) {
                result += it;
            }
            std::cout << "sum is " << result << " sleep time is " << cout << std::endl;
        }
        {
            std::lock_guard<std::mutex> lk2(ml);
            for (auto iter : maps) {
                std::cout << iter.first << " " << iter.second << (cout % 5 == 0 ? "\n" : " ");
            }
        }
        sleep(20);
    }
}

void ThreadFunc2()
{
    int cout = 0;
    while (true) {
        {
            std::lock_guard<std::mutex> lk2(ml);
            g_golbalves.push_back(cout);
        }
        cout++;
        std::cout << std::this_thread::get_id() << " " << cout << std::endl;
        sleep(4);
    }
}

std::string GetCurrentTime()
{
    time_t t = time(0);
    char time[64] = {0};
    strftime(time, sizeof(time) - 1, "%Y-%m-%d-%H%M%S", localtime(&t));
    return time;
}

void ThreadFunc3()
{
    int cout = 0;
    while (true) {
        {
            std::lock_guard<std::mutex> lk3(ml);
            maps[cout] = GetCurrentTime();
        }
        std::cout << std::this_thread::get_id() << " " << maps[cout] << " " << cout << std::endl;
        cout++;
        sleep(10);

    }
}

void ThreadFunc4()
{
    while (1)
    {
        {
            ReadLockGuard r(rw);
            std::cout << "read start lockguard " << GetCurrentTime() <<  "\n";
            sleep(30);
            std::cout << "read end lockguard " << GetCurrentTime() <<  "\n";
        }
    }
    
}

void ThreadFunc5()
{
    while (1)
    {
        {
            ReadLockGuard r(rw);
            std::cout << "read start lockguard1 " << GetCurrentTime() <<  "\n";
            sleep(30);
            std::cout << "read end lockguard1 " << GetCurrentTime() <<  "\n";
        }
    }
    
}

void ThreadFunc6()
{
    while (1)
    {
        {
            WriteLockGuard w(rw);
            std::cout << "write start lockguard " << GetCurrentTime() <<  "\n";
            sleep(30);
            std::cout << "write end lockguard " << GetCurrentTime() <<  "\n";
        }
    }
    
}

void ThreadF()
{
    std::cout << "start sleep never " << std::endl;
    sleep(1000000);
}

void ThreadFunc7()
{
    std::thread t(ThreadF);
    ThreadGuard bb(t);
    try
    {
        std::cout << "sleep 5\n";
        sleep(5);
        throw 5;
    }
    catch (int a)
    {
        std::cerr << a << '\n';
    }
    
}

class ThestCopyT {
public:
    ThestCopyT(std::thread t) : t1(std::move(t)) {}
    ~ThestCopyT()
    {
        if (t1.joinable()) {
            t1.join();
        }
    }

private:
    std::thread t1;

};

void TestMove()
{
    std::thread t(ThreadF);
    std::vector<std::thread> map;
    // map.push_back(t);g
    map.push_back(std::move(t));
    map.push_back(std::thread(ThreadF));
    std::thread t1(ThreadF);
    ThreadGuard tg(map[0]);
    ThestCopyT tc(std::move(t1));
}

std::mutex dl1;
std::mutex dl2;

void TestDeadL1()
{
    std::lock(dl1, dl2);
    std::cout << "lock 1 \n";
    sleep(5);
    std::cout << "lock 2 \n";
    dl1.unlock();
    dl2.unlock();
}

std::mutex m;

void TestFunpost()
{
    m.lock();
    std::cout << "post lock\n";
    m.unlock();
}

void TestFuncpre()
{
    m.lock();
    std::cout << "prelock \n";
    TestFunpost();
    std::cout << "pre lock\n";
    m.unlock();
}


void TestDeadL2()
{
    std::lock(dl2, dl1);
    std::cout << "lock 11 \n";
    sleep(5);
    std::cout << "lock 22 \n";
    dl1.unlock();
    dl2.unlock();
}

std::mutex ul;

std::atomic<int> g_cout(0);

std::unique_lock<std::mutex> getLock()
{
    std::unique_lock<std::mutex> ui(ul);
    std::cout << "wait time 5S " << GetCurrentTime() << "\n";
    sleep(5);
    std::cout << "wait time 5S\n";
    ++g_cout;
    return ui;
}

void TestMoveULock()
{
    std::unique_lock<std::mutex> ul(getLock());
    std::cout << "move unl " << g_cout << " " << GetCurrentTime() << "\n";

}

void TestDeadLock()
{
    std::thread t1(TestDeadL1);
    std::thread t2(TestDeadL2);
    std::thread t3(TestFuncpre);
    std::thread t4(TestMoveULock);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}

bool g_flag = false;
std::mutex mcv;
std::condition_variable conv;
void TestConv()
{
    std::unique_lock<std::mutex> ul(mcv);
    conv.wait(ul, []{return g_flag;});
    sleep(5);
    std::cout << GetCurrentTime() << "test conv 0\n";
}

void TestConv1()
{
    std::unique_lock<std::mutex> ul(mcv);
    conv.wait(ul, []{return g_flag;});
    sleep(5);
    std::cout << GetCurrentTime() << "test conv 1\n";
}

void TestConv2()
{
    std::unique_lock<std::mutex> ul(mcv);
    conv.wait(ul, []{return g_flag;});
    sleep(5);
    std::cout << GetCurrentTime() << "test conv 2\n";
}

void TestFlag()
{
    std::cout << "set flag " << GetCurrentTime() << std::endl;
    sleep(20);
    g_flag = true;
    std::cout << "set flag " << GetCurrentTime() << std::endl;
    conv.notify_all();
}

void TestFuncConv()
{
    std::thread t1(TestFlag);
    std::thread t2(TestConv1);
    std::thread t3(TestConv);
    std::thread t4(TestConv2);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}

std::once_flag one;

class OnceLock {
public:
    static OnceLock* Instance()
    {
        std::call_once(one, Init);
        return once;
    }

private:
    static void Init()
    {
        std::cout << "Init OnceLock\n";
        once = new OnceLock();
    }
    static OnceLock* once;
};

OnceLock* OnceLock::once = nullptr;

void TestOnceFlag()
{
    OnceLock* first = OnceLock::Instance();
    OnceLock* second = OnceLock::Instance();
    std::cout << first << "  " << second << std::endl;

}

void TestOnceFlag1()
{
    OnceLock* first = OnceLock::Instance();
    OnceLock* second = OnceLock::Instance();
    std::cout << first << "  " << second << std::endl;
}

void TestOnceFlagThread()
{
    std::thread t1(TestOnceFlag1);
    std::thread t2(TestOnceFlag);
    t1.join();
    t2.join();
}

int ReturnResult(int a)
{
    std::cout << "future " << std::this_thread::get_id() << std::endl;
    std::cout << "future " << GetCurrentTime() << std::endl;
    sleep(15);
    return a + 1;
}

void TestFuture()
{
    std::cout << "future pat " << std::this_thread::get_id() << " " << GetCurrentTime() << std::endl;
    std::future<int> asy = std::async(std::launch::async, ReturnResult, 99);
    int a = asy.get();
    std::cout << "future end " << GetCurrentTime() << " " << a << std::endl;
}

void TestPromise(std::promise<int>& vpromise)
{
    std::cout << "promise thread id " << GetCurrentTime() << "    " << std::this_thread::get_id() << std::endl;
    sleep(5);
    vpromise.set_value(1111);
    sleep(5);
    return ;
}

void TestPromiseThread()
{
    std::cout << "promise p thread id is " << GetCurrentTime() << "    " << std::this_thread::get_id() << std::endl;
    std::promise<int> result;
    std::future<int> futureR = result.get_future();
    std::thread t1(TestPromise, std::ref(result));
    t1.detach();
    while(futureR.wait_for(std::chrono::milliseconds(500)) != std::future_status::ready) {
        std::cout << ".. ";
    }
    

    std::cout << GetCurrentTime() << "   " << futureR.get() << std::endl;
    sleep(10);
}

int TestPackageTask(int a ,int &b)
{
    std::cout << "task thread id " << std::this_thread::get_id() << std::endl;
    b *= 2;
    sleep(10);
    return a + b;
}

void TestPackTaskThread()
{
    std::packaged_task<int (int, int&)> task(TestPackageTask);
    int a = 100;
    int b = 1000;
    std::future<int> futurep = task.get_future();
    std::cout << "lambda main id is " << GetCurrentTime() << "   " << std::this_thread::get_id() << std::endl;
    std::thread t1([&](){
        std::cout << "lambda thread id is " << GetCurrentTime() << "   " << std::this_thread::get_id() << std::endl;
        task(a, std::ref(b));
        std::cout << "task post " << GetCurrentTime() << std::endl;
        sleep(10);
    });
    t1.detach();
    while (futurep.wait_for(std::chrono::milliseconds(500)) != std::future_status::ready) {
        std::cout << ".. \n";
    }
    std::cout << futurep.get() << std::endl;
}

int PackageTask(int a, int&b)
{
    std::cout << GetCurrentTime() << " package thread share future " << std::this_thread::get_id() << std::endl;
    int c = b;
    b *= 2;
    return a + c;
}

void TestShareFuture()
{
    std::cout << GetCurrentTime() << " sharefuture thread " << std::this_thread::get_id() << std::endl;
    int a = 100;
    int b = 1000;
    std::packaged_task<int (int, int&)> task(PackageTask);
    std::future<int> future = task.get_future();
    std::thread t1([&](){
        std::cout << GetCurrentTime() << " share future thread child " << std::this_thread::get_id() << std::endl;
        task(a, std::ref(b));
        sleep(5);
    });
    t1.detach();

    while(future.wait_for(std::chrono::milliseconds(100)) != std::future_status::ready) {
        std::cout << "..\n";
    }
    
    std::shared_future<int> sharefuture = future.share();
    std::cout << sharefuture.get() << std::endl;
    std::shared_future<int> share = sharefuture;
    std::cout << share.get() << std::endl;
}