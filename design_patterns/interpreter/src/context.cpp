#include "context.h"

void BoolContext::Assign(std::string key, bool flag)
{
    cons[key] = flag;
}

bool BoolContext::LookUp(std::string name)
{
    if (cons.find(name) == cons.end()) {
        return false;
    }
    return cons.find(name)->second;
}