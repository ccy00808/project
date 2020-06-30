#include "timewheel.h"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
void TestFunc(void *arg)
{
    std::cout << *((int*)arg) << std::endl;
}

int num = 100;

int main()
{
    TimeWheel* timeWheel = TimeWheel::GetInstance();
    for(int i = 0; i < 100; ++i) {
        tagItemData item{TestFunc, &num};
        timeWheel->AddTimeoutEvent(item, i);
    }
    timeWheel->ShowTimeWheelInfo();

    timeWheel->EventLoop();
}