#include "charclass.h"
#include <iostream>

void CharValPerson::DisplayScreen()
{
    std::cout << name;
    if (charType) {
        charType->DisplayView();
    }
}

void CharValTeacher::DisplayScreen()
{
    std::cout << name;
    if (charType) {
        charType->DisplayView();
    }
}