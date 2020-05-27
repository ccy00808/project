#ifndef FLYBEHAVIOR_H_
#define FLYBEHAVIOR_H_

class FlyBehavior {
public:
    virtual void OperatorFly() = 0;
};

class HigherFly : public FlyBehavior {
public:
    void OperatorFly();
};

class LowerFly : public FlyBehavior {
public:
    void OperatorFly();
};

#endif