#include "context.h"
#include "expression.h"
#include <iostream>

int main()
{
    Context *context = new BoolContext();
    context->Assign("x", false);
    context->Assign("ye", true);

    TerminalExpression *ter1 = new TerminalExpression("ye");
    TerminalExpression *ter2 = new TerminalExpression("x");

    std::cout << (new AndExp(ter1, ter2))->Evaluate(context) << std::endl;
}