#ifndef QUACKBEHAVIOR_H_
#define QUACKBEHAVIOR_H_

class QuackBehavior {
public:
    virtual void OperatorQuack() = 0;
};

class WaterQuack : public QuackBehavior {
public:
    void OperatorQuack();
};

class BoomQuack : public QuackBehavior {
public:
    void OperatorQuack();
};

#endif