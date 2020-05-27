#include "receiver.h"
#include <iostream>

void Light::Action(int opt)
{
    if (status != 1 && opt == 1) {
        std::cout << "Light " << id << " is light\n";
        status = 1;
        return ;
    } else if (status != 0 && opt == 0) {
        std::cout << "Light " << id << " is off\n";
        status = 1;
        return ;
    }

    std::cout << "current status is match status " << status << " opt " << opt << std::endl;
    
}