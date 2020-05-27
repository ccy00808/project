#include <thread>
#include <functional>
#include <iostream>

typedef void (*TEST_FUNC_PTR)(int a, int b);
using TEST_FUNC_PUS = void (*)(int a, int b);

void Func(int a, int b) {
    std::cout << a << b << std::endl;
}

void TestFunc(TEST_FUNC_PTR funcp)
{
    funcp(100, 99);
}

void TestFuncUs(TEST_FUNC_PUS funcu)
{
    funcu(1000, 999);
}

void TestFunction(std::function<void (int, int)> f)
{
    f(1, 2);
}

class AA {
public:
    static void Func(int a, int b) {
        std::cout << a << b << std::endl;
    }

    void TestFunc(int a, int b) {
        std::cout << a << b << std::endl;
    }
};

int main()
{
    TestFunc(Func);
    TestFuncUs(Func);
    TestFunction(Func);
    std::function<void (int, int)> f = Func;
    f(3, 4);
    f = &AA::Func;
    f(5, 6);

    void (AA::*ff)(int, int) = &AA::TestFunc;
    AA a;
    (a.*ff)(7, 8);
    
}