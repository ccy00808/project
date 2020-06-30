#include "timewheel.h"
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int g_timeItemNum = 0;

long long GetCurrentTimeS()
{
    struct timeval time;
    gettimeofday(&time, NULL);
    return time.tv_sec;
}

TimeWheel* TimeWheel::instance = nullptr;

TimeWheel* TimeWheel::GetInstance()
{
    if (!instance) {
        instance = new TimeWheel();
    }
    return instance;
}

void TimeWheel::EventLoop()
{
    for(;;) {
        usleep(500 * 1000);
        long long curT = GetCurrentTimeS();
        int dif = curT - curTime;
        std::cout << "****** " << curTime << " ******* " << GetCurrentTimeS() << std::endl;
        GetTimeoutEventForWheelTolist(dif);
        Process();
    }
}

void TimeWheel::Process()
{
    WheelItem* item = timeoutEventList.head;
    while (item) {
        DataItem &data = item->data;
        std::cout << item->id << " ";
        data.CallBackFunc(data.arg);
        WheelItem *tmp = item;
        item = item->next;
        free(tmp);
    }
    
    timeoutEventList.head = timeoutEventList.tail = nullptr;
}

void TimeWheel::AddTimeoutEvent(DataItem item, int timeout)
{
    WheelItem *itemW = new WheelItem();
    itemW->data = item;
    itemW->timeout = curTime + timeout;
    itemW->pre = itemW->next = nullptr;
    itemW->id = g_timeItemNum++;
    int tmpSlot = curSlot + timeout;
    WheelItemLink &link = wheel[tmpSlot % MAX_TIME_WHEEL_NUM];
    if (link.tail) {
        link.tail->next = itemW;
        itemW->pre = link.tail;
        link.tail = itemW;
    } else {
        link.head = link.tail = itemW;
    }
}

void TimeWheel::ShowTimeWheelInfo()
{
    for(int i = 0; i < 200; ++i) {
        std::cout << "whell slot is " << i;
        WheelItem* item = wheel[i].head;
        while(item) {
            std::cout << " " << item->id << " ";
            item = item->next;
        }
        std::cout << std::endl;
    }
}

void TimeWheel::GetTimeoutEventForWheelTolist(int diff)
{
    for (int i = 0; i < diff; ++i) {
        WheelItemLink &link = wheel[(curSlot + i) % MAX_TIME_WHEEL_NUM];
        if (timeoutEventList.tail) {
            timeoutEventList.tail->next = link.head;
            if (link.head) {
                link.head->pre = timeoutEventList.tail;
            }
        } else {
            timeoutEventList.head = link.head;
            timeoutEventList.tail = link.tail;
        }
        link.head = link.tail = nullptr;
    }

    curTime += diff;
    curSlot = (curSlot + diff) % MAX_TIME_WHEEL_NUM;
}