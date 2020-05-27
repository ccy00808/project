#ifndef INVOKER_H_
#define INVOKER_H_
#include <string>
#include <memory>
#include "command.h"

class Invoker {
public:
    virtual void response(int oper = -1) = 0;
};

class Person : public Invoker {
public:
    Person() = default;
    Person(std::string na, Command::CommandPtr cmd) : name(na), command(cmd) {}
    virtual void response(int oper);

private:
    std::string name;
    Command::CommandPtr command;

};

#endif