#include "receiver.h"
#include <iostream>

void Light::Action()
{
    OnLight();
}

void Light::UnAction()
{
    OffLight();
}

void Light::OnLight()
{
    if (status == STATUS_ON_TYPE) {
        std::cout << "current status has on\n";
        return ;
    }

    status = STATUS_ON_TYPE;
    std::cout << "status is change on\n";
    return ;
}

void Light::OffLight()
{
    if (status = STATUS_ON_TYPE) {
        std::cout << "Light dont off\n";
        return ;
    }

    status = STATUS_OFF_TYPE;
    std::cout << "Light status change off\n";
}

void TV::Action()
{
    if (status == STATUS_ON_TYPE) {
        std::cout << "TV status is on, not again open\n";
        return ;
    }

    status = STATUS_ON_TYPE;
    std::cout << "TV status haa changed on\n";
}

void TV::UnAction()
{
    if (status == STATUS_ON_TYPE) {
        status = STATUS_OFF_TYPE;
        std::cout << "TV status has changed off\n";
        return ;
    }

    std::cout << "TV cannt off\n";
}