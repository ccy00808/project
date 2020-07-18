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