#ifndef TIME_WHEEL_H_
#define TIME_WHEEL_H_

#include <functional>
#include <list>

#define MAX_TIME_WHEEL_NUM (60 * 60)
typedef struct tagItemData{
    std::function<void (void *)> CallBackFunc;
    void *arg;
} DataItem;

struct tagItemWheelLink;

typedef struct tagItemWheel {
    DataItem data;
    long long timeout;
    int slot;
    tagItemWheel *pre;
    tagItemWheel *next;
    unsigned int id;
} WheelItem;

typedef struct tagItemWheelLink {
    WheelItem* head;
    WheelItem* tail;
} WheelItemLink;

long long GetCurrentTimeS();

class TimeWheel {
public:
    static TimeWheel* GetInstance();
    void AddTimeoutEvent(DataItem item, int timeout);
    void EventLoop();
    void ShowTimeWheelInfo();

private:
    TimeWheel() : curTime(GetCurrentTimeS()), curSlot(0) {}
    TimeWheel(const TimeWheel&) = delete;
    TimeWheel& operator=(const TimeWheel&) = delete;
    void GetTimeoutEventForWheelTolist(int diff);
    void PopItem();
    void Process();

private:
    static TimeWheel* instance;
    int wheelLen = MAX_TIME_WHEEL_NUM;
    WheelItemLink wheel[MAX_TIME_WHEEL_NUM] = {{nullptr, nullptr}};
    long long curTime;
    int curSlot;
    
    WheelItemLink timeoutEventList;
};

#endif