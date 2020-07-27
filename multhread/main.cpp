#include "multhread.h"
#include <thread>
#include <vector>
#include <execinfo.h>

int PrintBackTrace()
{
    void* buf[100];
    int btSize = backtrace(buf, 100);
    char** btResult = backtrace_symbols(buf, btSize);
    for (int i = 0; i < btSize; ++i) {
        std::cout << btResult[i] << std::endl;
    }
}

int FuncA()
{
    std::cout << "FuncA\r\n";
    PrintBackTrace();
    return 0;
}

int FuncB()
{
    std::cout << "FuncB\r\n";
    FuncA();
    return 0;
}

int main()
{
    std::cout << "main thread id " << std::this_thread::get_id() << std::endl;
    FuncB();
    // TestFuture();
    // std::vector<std::thread> mts;
    // mts.push_back(std::thread(ThreadFunc1));
    // mts.push_back(std::thread(ThreadFunc2));
    TestShareFuture();
    TestPromiseThread();
    TestPackTaskThread();
    // mts.push_back(std::thread(ThreadFunc6));
    // mts.push_back(std::thread(ThreadFunc4));
    // mts.push_back(std::thread(ThreadFunc5));
    // TestOnceFlagThread();
    // TestFuncConv();
    // MyThread my;
    // mts.push_back(std::thread(my));
    // TestDeadLock();
    
    // ThreadFunc7();
    // for (auto &t1 : mts) {
    //     if (t1.joinable()) {
    //         t1.join();
    //     }
    // }
}