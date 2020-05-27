#include "handler.h"
#include <memory>

int main()
{
    
    Handler::HandlerPtr hp = std::make_shared<Application>();
    Handler::HandlerPtr bp = std::make_shared<Button>(hp, BUTTON_OPERATOR_CMD);
    Handler::HandlerPtr vp = std::make_shared<View>(bp);
    vp->HelpHandler();
}