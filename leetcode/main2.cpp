#include <stdlib.h>
#include <iostream>
#include <type_traits>
#include <stdarg.h>
#include <memory>

class A {
    public:
    A() {
        buf = (char*)malloc(512);
        printf("%lu   ", buf);
        std::cout << "construct\n";
    }

    A(const A&){
        std::cout << "copy construct\n";
    }

    ~A() {
        std::cout << "destruct\n";
        if(buf) {
            free(buf);
        }
    }

    void PrintInfo() {
        printf("%lu  \n", buf);
    }

    A(A&& a) : buf(a.buf) {
        a.buf = nullptr;
    }

private:
    char *buf;
    
};

class B : public A {

};

typedef unsigned int  uint;

void ArgsFunc(char *s, ...)
{
    va_list arg_ptr;
    va_start(arg_ptr, s);
    std::cout << s << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << va_arg(arg_ptr, int) << '\t';
    }

    va_end(arg_ptr);
}

void SharePtrTest()
{
    std::shared_ptr<int> pInt = std::make_shared<int>(100);
    int b = 0;
    int *a = new int(100);

    std::shared_ptr<int> c(a);

    std::cout << *pInt << std::endl;

    std::shared_ptr<int> pi = pInt;

    std::shared_ptr<int> pin(pInt);

    if (pInt != nullptr) {
        std::cout << "true\n";
    } else {
        std::cout << "false\n";
    }
}

void UniquePtrTest() {
    std::unique_ptr<int> pInt(new int(100));

    std::cout << *pInt;

    std::unique_ptr<int> pi(std::move(pInt));

    if (pInt == nullptr) {

        std::cout << "pint is null\n";
    }
}

int main()
{
    A a;
    a.PrintInfo();

    A b = std::move(a);
    b.PrintInfo();

    std::cout << std::is_base_of<A, B>::value << std::endl;
    std::cout << std::is_base_of<B, A>::value << std::endl;
    std::cout << std::is_same<unsigned int, uint>::value << std::endl;
    std::cout << std::is_same<A, B>::value << std::endl;
    std::cout << std::is_convertible<B*, A*>::value << std::endl;

    std::cout << "********\n";
    ArgsFunc("hello", 1, 2 ,3 ,4 ,5 , 6, 7, 8, 9, 10);

    SharePtrTest();

    char *mem = (char *)malloc(128);

    UniquePtrTest();

}