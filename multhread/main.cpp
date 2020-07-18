#include "multhread.h"
#include <thread>
#include <vector>

int main()
{
    std::cout << "main thread id " << std::this_thread::get_id() << std::endl;
    std::vector<std::thread> mts;
    // mts.push_back(std::thread(ThreadFunc1));
    // mts.push_back(std::thread(ThreadFunc2));
    mts.push_back(std::thread(ThreadFunc6));
    mts.push_back(std::thread(ThreadFunc4));
    mts.push_back(std::thread(ThreadFunc5));
    MyThread my;
    mts.push_back(std::thread(my));
    ThreadFunc7();
    for (auto &t1 : mts) {
        if (t1.joinable()) {
            t1.join();
        }
    }
}