#include "expression.h"

bool TerminalExpression::Evaluate(Context *context)
{
    return context->LookUp(exp);
}

bool AndExp::Evaluate(Context *context)
{
    return exp1->Evaluate(context) && exp2->Evaluate(context);
}

bool OrExp::Evaluate(Context *context)
{
    exp1->Evaluate(context) || exp2->Evaluate(context);
}

bool ContactExp::Evaluate(Context *context)
{
    return flag;
}