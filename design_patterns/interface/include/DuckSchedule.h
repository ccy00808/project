#ifndef DUCKSCHEDULE_H_
#define DUCKSCHEDULE_H_

#include <map>
#include "Duck.h"

class DuckSchedule {
public:
    void PerformaceHavior();
    void AddDuck(Duck duck);
    void SetDuck(Duck duck);
    void DelDuck(Duck duck);

private:
    std::map<int, Duck> duckVec;
};

#endif