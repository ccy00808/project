#include <iostream>
#include <memory>
#include <thread>
#include <functional>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <ctime>
#include <atomic>
#include <iomanip>

void TestThread(int &a, int b)
{
    std::cout << std::this_thread::get_id() << " " << a << " " << b << std::endl;
}

struct Thread_Struct
{
    int a;
    int b;
};

class TestThreadLock {
public:
    void Test(struct Thread_Struct *s, int &b) {
        {
            std::lock_guard<std::recursive_mutex> lock(remutex);
            s->a = 1000;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            s->b = 1001;
            b = 1002;
        }
        
    }

private:
    std::mutex mutex;
    std::recursive_mutex remutex;
    
};
std::string GetTime() {
    time_t timep;
    time(&timep);
    return asctime(gmtime(&timep));
}

bool flag = false;

class Condition {
public:
    void TestFunc(){
        {
            std::unique_lock<std::mutex> lock(mutex);
            std::cout << GetTime() << "1*\n";
            cond.wait_for(lock, std::chrono::seconds(10), [&](){return flag;});
            std::cout << GetTime() << std::this_thread::get_id() << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(3000));
            std::cout << "*****\n";
        }
    }
 
    void TestFun() {
        {
            std::lock_guard<std::mutex> lock(mutex);
            std::cout << "2*\n";
            flag = true;
            // std::this_thread::sleep_for(std::chrono::minutes(100));
            // cond.notify_one();
        }
    }

private:
    std::mutex mutex;
    std::condition_variable cond;
};

//std::atomic<int> intf(0);
int intf = 0;

void TestAtomic()
{
    for(int i = 0; i < 100000000; ++i) {
        ++intf;
    }
}



int main()
{
    int a = 100;
    std::thread t1(std::bind(TestThread, 1, a));
    std::thread t2(TestThread, std::ref(a), 100);
    t2.join();
    t1.join();

    TestThreadLock aa;
    struct Thread_Struct s = {1,100};
    int c = 5;

    std::thread t3(std::bind(&TestThreadLock::Test, &aa, &s, std::ref(c)));
    t3.join();
    std::cout << a << std::endl;
    std::cout << s.a << s.b << c << std::endl;

    std::cout << "*******\n";
    Condition ab;
    std::thread t5(&Condition::TestFunc, &ab);
    
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    
    std::thread t6(&Condition::TestFun, &ab);
    t5.join();
    t6.join();

    std::thread t7(TestAtomic);
    std::thread t8(TestAtomic);
    t7.join();
    t8.join();

    std::cout << std::endl << intf << std::endl;
}