#ifndef RECEIVER_H_
#define RECEIVER_H_
#include <memory>

class Receiver {
public:
    using ReceiverPtr = std::shared_ptr<Receiver>;
    Receiver(int i) : id(i)
    {
        status = 0;
    }
    virtual ~Receiver() {}
    virtual void Action(int opt = 0) = 0;

protected:
    int id;
    int status;
};


class Light : public Receiver {
public:
    Light(int i) : Receiver(i) {}
    virtual ~Light() {}
    virtual void Action(int opt);
};

#endif