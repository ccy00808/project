#ifndef TIME_CIRCLE_H_
#define TIME_CIRCLE_H_

#include <functional>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <list>

#define TIME_CIRCLE_LEN (60 * 60)

typedef void (*OperatorFunc)(void* args);

typedef struct {
    std::function<void (void *)> CallBackFunc;;
    void *args;
} DataCentor;

typedef struct Item {
    DataCentor data;
    int outTime;
    Item* pre;
    Item* next;
} TimeItem;

typedef struct ItemLink {
    TimeItem* head;
    TimeItem* tail;
}TimeItemLink;

class TimeCircle {
public:
    static TimeCircle* Instance();
    void AddLink(TimeItemLink* link, TimeItem *item);
    void EventLoop();
    void ActionRequest();

private:
    TimeCircle() = default;
    TimeCircle(const TimeCircle&) = delete;
    TimeCircle& operator=(const TimeCircle&) = delete;
    void RmvLink(TimeItemLink *link, TimeItem *item);
    long long GetCurrentTime();
    void MvItemFormLinkToList(long long timeout);

private:
    int TimeCirleLen = TIME_CIRCLE_LEN;
    TimeItemLink itemCircle[TIME_CIRCLE_LEN];
    int curSlot;
    int curTime;
    static TimeCircle* instance;
    std::list<TimeItem *> timeout;

    std::mutex mutex;
    std::condition_variable condition;
};

#endif