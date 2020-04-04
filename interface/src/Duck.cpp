#include "Duck.h"

int Duck::totalDuck = 0;

Duck::Duck(FlyBehavior *tempFly, QuackBehavior *tempQuack) : fly(tempFly), quack(tempQuack), id(Duck::totalDuck++) {};

void Duck::OperatorFly()
{
    fly->OperatorFly();
}

void Duck::OperatorQuack()
{
    quack->OperatorQuack();
}

void Duck::SetFly(FlyBehavior *tempFly)
{
    fly = tempFly;
    return ;
}

void Duck::SetQuack(QuackBehavior *tempQuack)
{
    quack = tempQuack;
}