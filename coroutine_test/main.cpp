#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "coroutine.h"

int a = 100;
struct input {
    int a = 100;
    int b = 1000;
};

void func(struct Schdule *schdule, void *args)
{
    struct input *in = (struct input *)args;
    printf("cor %d %d %d start\n", GetRuningId(schdule), in->a, in->b);
    YieldCoroutine(schdule);
    printf("cor %d %d %d end\n", GetRuningId(schdule), in->a, in->b);
}

int main()
{
    struct input test, test1;
    test.a = 1;
    test.b = 2;
    test1.a = 3;
    test1.b = 4;
    struct Schdule *schdule = CreateCoroutineSchdule();
    unsigned int cor1 = CreateCoroutine(schdule, func, &test);
    unsigned int cor2 = CreateCoroutine(schdule, func, &test1);
    while (GetCouroutineStatus(schdule, cor1) != COROUTINE_DEAD && GetCouroutineStatus(schdule, cor2) != COROUTINE_DEAD) {
        ResumeCoroutine(schdule, cor1);
        printf("**********\n");
        ResumeCoroutine(schdule, cor2);
    }
}