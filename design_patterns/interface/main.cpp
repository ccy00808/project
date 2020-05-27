#include <stdio.h>
#include <iostream>
#include "Duck.h"
#include "DuckSchedule.h"
#include "QuackBehavior.h"
#include "FlyBehavior.h"
#include <stdlib.h>

int main()
{
    FlyBehavior *higerFly = new HigherFly();
    FlyBehavior *lowerfly = new LowerFly();
    QuackBehavior *water = new WaterQuack();
    QuackBehavior *boom = new BoomQuack();
    Duck duck1(lowerfly, water);
    DuckSchedule schedule;
    schedule.AddDuck(duck1);
    schedule.PerformaceHavior();
    std::cout << "test print!\n";
    delete higerFly;
    delete lowerfly;
    delete water;
    delete boom;
}