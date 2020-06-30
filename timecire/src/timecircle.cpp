#include "timecircle.h"
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

void TimeCircle::AddLink(TimeItemLink* link, TimeItem *item)
{
    if(!link->head) {
        link->head = link->tail = item;
    } else {
        link->tail->next = item;
        item->pre = link->tail;
    }

    return;
}

void Process(DataCentor data)
{
    return data.CallBackFunc(data.args);
}

void TimeCircle::EventLoop()
{
    for (;;) {
        sleep(2);
        long long dif = GetCurrentTime() - curTime;
        MvItemFormLinkToList(dif);
        condition.notify_all();
    }
}

void TimeCircle::MvItemFormLinkToList(long long out)
{
    for (int i = 0; i < out; ++i) {
        while (itemCircle[(curSlot + i) % TIME_CIRCLE_LEN].head)
        {
            timeout.push_back(itemCircle[(curSlot + i) % TIME_CIRCLE_LEN].head);
            RmvLink(&itemCircle[(curSlot + i) % TIME_CIRCLE_LEN], itemCircle[(curSlot + i) % TIME_CIRCLE_LEN].head);
        }
        
    }

    curSlot = (curSlot + out) % TIME_CIRCLE_LEN;
    curTime += out;
}

void TimeCircle::ActionRequest()
{
    for(;;) {
        std::unique_lock<std::mutex> lock(mutex);
        condition.wait(lock, [&] { return !timeout.empty();});
        TimeItem *item = timeout.front();
        Process(item->data);
        timeout.pop_front();
        free(item);
    }
}

long long TimeCircle::GetCurrentTime()
{
    struct timeval time;
    gettimeofday(&time, NULL);
    return time.tv_sec;    
}

void TimeCircle::RmvLink(TimeItemLink *link, TimeItem *item)
{
    if (link->head == item) {
        link->head = link->tail = nullptr;
    } else {
        item->pre->next = item->next;
        if (item->next) {
            item->next->pre = item->pre;
        }
    }
}

TimeCircle* TimeCircle::Instance()
{
    if (!instance) {
        instance = new TimeCircle();
    }
    return instance;
}