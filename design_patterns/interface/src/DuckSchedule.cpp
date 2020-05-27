#include "DuckSchedule.h"

void DuckSchedule::PerformaceHavior()
{
    for(auto iter = duckVec.begin(); iter != duckVec.end(); ++iter) {
        iter->second.OperatorFly();
        iter->second.OperatorQuack();
    }
}

void DuckSchedule::AddDuck(Duck duck)
{
    duckVec.insert(std::pair<int, Duck>(duck.GetId(), duck));
    return ;
}

void DuckSchedule::SetDuck(Duck duck)
{
    duckVec[duck.GetId()] = duck;
    return ;
}

void DuckSchedule::DelDuck(Duck duck)
{
    duckVec.erase(duck.GetId());
    return ;
}