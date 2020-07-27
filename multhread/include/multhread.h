#ifndef MUL_THREAD_H_
#define MUL_THREAD_H_
#include <thread>
#include <iostream>

void ThreadFunc1();

void ThreadFunc2();

void ThreadFunc3();

void ThreadFunc4();

void ThreadFunc5();

void ThreadFunc6();
void TestFuncConv();
void TestOnceFlagThread();
void TestFuture();
void TestPromiseThread();
void TestPackTaskThread();
void TestShareFuture();

class MyThread {
public:
    MyThread() = default;
    void operator()()
    {
        std::cout << std::this_thread::get_id() << " ccy \n";
    }
};

class ThreadGuard {
public:
    ThreadGuard(std::thread& t) : t(t) {}
    ~ThreadGuard()
    {
        if (t.joinable()) {
            t.join();
        }
    }

private:
    std::thread& t;
};

void ThreadFunc7();

void TestDeadLock();

#endif