#ifndef COMMAND_H_
#define COMMAND_H_
#include "receiver.h"
#include <memory>
#include <unordered_map>

class Command {
public:
    using ReceiverPtr = std::shared_ptr<Receiver>;
    Command() {}
    virtual ~Command() {}
    virtual void Execute(void *context) = 0;
    virtual void Undo(void *context) = 0;
};

class LightCommand : public Command {
public:
    LightCommand(Command::ReceiverPtr p = nullptr, int pos = 0);
    virtual ~LightCommand() {}
    virtual void Execute(void *context = nullptr);
    virtual void Undo(void *context = nullptr);
    void RegisterLight(int pos, Command::ReceiverPtr);
    void UnRegisterLight(int id);

    
private:
    void ExecuteAll();
    void UndoAll();
    std::unordered_map<int, Command::ReceiverPtr> lights;
};

class TVCommand : public Command {
public:
    TVCommand(Command::ReceiverPtr p = nullptr) : ptr(p) {}
    virtual ~TVCommand() {}
    virtual void Execute(void *context);
    virtual void Undo(void *context);

private:
    Command::ReceiverPtr ptr;
};

template<typename T>
class SimpleCommand : public Command {
    typename void (T::* Action)();
    typename void (T::* UnAction)();
public:
    SimpleCommand(Command::ReceiverPtr p, Action fun, UnAction unFun) : ptr(p), func(fun), unFunc(unFun) {}
    virtual void Execute(void *context = nullptr)
    {
        ptr->func();
    }
    virtual void Undo(void *context = nullptr)
    {
        ptr->UndoFunc();
    }

private:
    Command::ReceiverPtr ptr;
    Action func;
    UnAction unFunc;

};

#endif