#include <iostream>
#include <functional>
#include "test.h"

using Func = std::function<void ()>;

Func funcs[] = {
    TestPointQuote
};


int main()
{
    int size = sizeof(funcs)/sizeof(funcs[0]);
    for (int i = 0; i < size; ++i) {
        funcs[i]();
    }
}