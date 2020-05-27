#ifndef COMMAND_H_
#define COMMAND_H_
#include <memory>
#include <unordered_map>
#include "receiver.h"

class Command {
public:
    using CommandPtr = std::shared_ptr<Command>;
    virtual void Execute(int pos = -1) = 0;
};

class LightCommand : public Command {
public:
    LightCommand(Receiver::ReceiverPtr p) : receiver(p) {}
    virtual void Execute(int pos);

private:
    Receiver::ReceiverPtr receiver;
};

class LightsCommand : public Command {
public:
    LightsCommand() {}
    void RegisterCommand(int pos, Command::CommandPtr ptr);
    void UngisterCommand(int pos);
    virtual void Execute(int pos);
    
private:
    std::unordered_map<int, Command::CommandPtr> onCommands;
    std::unordered_map<int, Command::CommandPtr> offCommands;
};

template<typename T>
class CommCommand : public Command {
    typedef void (T::* Action)(int opt);
public:
    CommCommand(T *p, Action ac) : recv(p), action(ac) {};
    virtual ~CommCommand() { delete recv; }
    virtual void Execute(int pos) { (recv->*action)(pos); }

private:
    Action action;
    T *recv;
};

#endif