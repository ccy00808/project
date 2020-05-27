#ifndef DUCK_H_
#define DUCK_H_
#include "FlyBehavior.h"
#include "QuackBehavior.h"

class Duck {
public:
    Duck() : fly(nullptr), quack(nullptr) {
        id = Duck::totalDuck++;
    }
    Duck(FlyBehavior *fly, QuackBehavior *quack);
    void OperatorFly();
    void OperatorQuack();

    void SetFly(FlyBehavior *fly);
    void SetQuack(QuackBehavior *quack);

    int GetId()
    {
        return id;
    }
    static int totalDuck;
private:
    int id;
    FlyBehavior *fly;
    QuackBehavior *quack;
};

#endif