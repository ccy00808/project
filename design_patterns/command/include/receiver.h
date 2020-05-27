#ifndef REVEIVER_H_
#define REVEIVER_H_

enum LightType {
    STATUS_INIT_TYPE,
    STATUS_ON_TYPE,
    STATUS_OFF_TYPE
};

class Receiver {
public:
    Receiver() {}
    virtual ~Receiver() {}
    virtual void Action() = 0;
    virtual void UnAction() = 0;
private:
};

class Light : public Receiver {
public:
    Light(int stu = STATUS_INIT_TYPE) : status(stu), Receiver() {}
    virtual ~Light() {}
    virtual void Action();
    virtual void UnAction();

private:
    void OnLight();
    void OffLight();

private:
    int status;
};

class TV : public Receiver {
public:
    TV(int s = STATUS_INIT_TYPE) :status(s), Receiver() {}
    virtual ~TV() {}
    virtual void Action();
    virtual void UnAction();

private:
    int status;
};




#endif