#include "handler.h"
#include <iostream>

#define HANDLER_HELP_FUNC(context)      \
    do {                                \
        if (HasOpt()) {                 \
            std::cout << context;       \
        } else {                        \
            if (handler != nullptr) {   \
                handler->HelpHandler(); \
            }                           \
        }                               \
    } while(0);

void View::HelpHandler()
{
    HANDLER_HELP_FUNC("view helper \n")
}

void Button::HelpHandler()
{
    HANDLER_HELP_FUNC("button helper \n")
}

void Application::HelpHandler()
{
    HANDLER_HELP_FUNC("Application helper \n")
}

bool Application::HasOpt()
{
    return true;
}