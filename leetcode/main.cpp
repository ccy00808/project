#include <stdlib.h>
#include <iostream>
#include <type_traits>

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

}