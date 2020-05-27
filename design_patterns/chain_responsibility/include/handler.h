#ifndef HANDLE_H_
#define HANDLE_H_

#include <memory>

#define NO_OPERATOR_CMD 0
#define VIER_OPERATOR_CMD 1
#define BUTTON_OPERATOR_CMD 2
#define APPLICATION_OPERATOR_CMD 3

class Handler {
public:
    using HandlerPtr = std::shared_ptr<Handler>;
    Handler(HandlerPtr p = nullptr, int cmd = NO_OPERATOR_CMD) : handler(p), cmdId(cmd) {}
    virtual ~Handler() {}
    virtual bool HasOpt()
    {
        return cmdId != NO_OPERATOR_CMD;
    }
    
    virtual void HelpHandler() = 0;

protected:
    HandlerPtr handler;
    int cmdId;
};

#define DEFINE_CLASS_COMM_FUNC(className, baseClassName) \
        className(baseClassName::HandlerPtr p = nullptr, int cmd = NO_OPERATOR_CMD) : baseClassName(p, cmd) {} \
        virtual ~className() {}

class View : public Handler {
public:
    DEFINE_CLASS_COMM_FUNC(View, Handler)
    virtual void HelpHandler() override final;

private:

};

class Button : public Handler {
public:
    DEFINE_CLASS_COMM_FUNC(Button, Handler)
    virtual void HelpHandler() override final;

private:

};

class Application : public Handler {
public:
    DEFINE_CLASS_COMM_FUNC(Application, Handler)
    virtual void HelpHandler() override final;
    virtual bool HasOpt();

private:
};

#endif