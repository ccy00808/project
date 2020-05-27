#include "invoker.h"
#include <iostream>

void Person::response(int oper)
{
    if (command != nullptr) {
        command->Execute(oper);
    }
}