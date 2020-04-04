#include "coroutine.h"
#include <ucontext.h>
#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define STACK_SIZE 8 * 1024
#define COROUTINE_NAXSIZE 16
#define COROUTINE_BUSY (-1)

struct Coroutine;

struct Schdule
{
    char stack[STACK_SIZE];
    ucontext_t main;
    unsigned int corCap;
    unsigned int corNum;
    unsigned int runingId;
    struct Coroutine **cors;
};

struct Coroutine {
    COROUTINE_FUNC func;
    void *args;
    ucontext_t ctx;
    struct Schdule *schdule;
    CoroutineStatus status;
    unsigned int cap;
    unsigned int size;
    char *buf;
};

Schdule* CreateCoroutineSchdule()
{
    struct Schdule *s = (struct  Schdule*)(malloc(sizeof(struct Schdule)));
    memset(s, 0, sizeof(struct Schdule));

    s->corCap = COROUTINE_NAXSIZE;
    s->corNum = 0;
    s->runingId = -1;
    s->cors = (struct Coroutine **)malloc(sizeof(struct Coroutine *) * COROUTINE_NAXSIZE);
    memset(s->cors, 0, sizeof(struct Coroutine *) * COROUTINE_NAXSIZE);
    return s;
}

void DeleteCoroutine(Coroutine *co)
{
    if (co != nullptr) {
        free(co->buf);
        free(co);
    } 
}

unsigned int RmvCoroutineScdule(struct Schdule *schdule)
{
    if (GetRuningId(schdule) != -1) {
        return COROUTINE_BUSY;
    }

    for (int i = 0; i < schdule->corCap; ++i) {
        DeleteCoroutine(schdule->cors[i]);
    }
    free(schdule->cors);
    free(schdule);
}

struct Coroutine * NewCoroutine(struct Schdule *schdule, COROUTINE_FUNC func, void *args)
{
    struct Coroutine *cor = (struct Coroutine *)malloc(sizeof(struct Coroutine));
    memset(cor, 0, sizeof(struct Coroutine));
    cor->func = func;
    cor->args = args;
    cor->schdule = schdule;
    cor->status = COROUTINE_READY;
    cor->size = 0;
    cor->cap = 0;
    cor->buf = nullptr;
    return cor;
}

void ExtenedCoroutineSpace(struct Schdule *schdule)
{
    unsigned int exCorCap = schdule->corCap * 2;
    struct Coroutine ** cor = (struct Coroutine **)malloc(sizeof(struct Coroutine *) * exCorCap);
    memset(cor, 0, sizeof(struct Coroutine *) * exCorCap);
    memcpy(cor, schdule->cors, sizeof(struct Coroutine *) * schdule->corCap);
    free(schdule->cors);
    schdule->cors = cor;
    schdule->corCap = exCorCap;
}

unsigned int SearchFreeCoroutine(struct Schdule *schdule)
{
    int freeCorId = 0;
    if (schdule->corNum >= schdule->corCap) {
        ExtenedCoroutineSpace(schdule);
        freeCorId = schdule->corNum;
    } else {
        for (int i = 0; i < schdule->corCap; ++i) {
            unsigned int tempCorId = (i + schdule->corNum) % schdule->corCap;
            if (schdule->cors[tempCorId] == nullptr) {
                freeCorId = tempCorId;
                break;
            }
        }
    }
    return freeCorId;
}

unsigned int CreateCoroutine(struct Schdule *schdule, COROUTINE_FUNC func, void *args)
{
    struct Coroutine *cor = NewCoroutine(schdule, func, args);
    unsigned int corId = SearchFreeCoroutine(schdule);
    schdule->cors[corId] = cor;
    ++schdule->corNum;
    return corId;
}

unsigned int GetRuningId(struct Schdule *schdule)
{
    return schdule->runingId;
}

unsigned int GetCouroutineStatus(struct Schdule *schdule, unsigned int corId)
{
    if (corId < schdule->corCap && schdule->cors[corId] != nullptr) {
        return schdule->cors[corId]->status;
    } else {
        return COROUTINE_DEAD;
    }
}

void HandleFunc(uint32_t low, uint32_t hig)
{
    intptr_t sc = (intptr_t)low | ((intptr_t)(hig << 32));
    struct Schdule *schdule = (struct Schdule *)sc;
    struct Coroutine *cor = schdule->cors[schdule->runingId];
    cor->func(schdule, cor->args);
    DeleteCoroutine(cor);
    schdule->cors[schdule->runingId] = nullptr;
    --schdule->corNum;
    schdule->runingId = -1;
}

unsigned int ResumeCoroutine(struct Schdule *schdule, unsigned int corId)
{
    if (corId >= schdule->corCap || schdule->cors[corId] == nullptr) {
        return -1;
    }

    
    struct Coroutine *cor = schdule->cors[corId];
    unsigned int corStatus = cor->status;
    intptr_t args = (intptr_t)schdule;
    switch (corStatus) {
        case COROUTINE_READY:
            getcontext(&cor->ctx);
            cor->ctx.uc_stack.ss_sp = schdule->stack;
            cor->ctx.uc_stack.ss_size = STACK_SIZE;
            cor->ctx.uc_link = &schdule->main;
            makecontext(&cor->ctx, (void (*)(void))HandleFunc, 2, (uint32_t)args, (int32_t)(args>>32));
            break;

        case COROUTINE_YIELD:
            memcpy(schdule->stack + STACK_SIZE - cor->size, cor->buf, cor->size);
            break;

        default:
            return -1;
    }
    schdule->runingId = corId;
    cor->status = COROUTINE_RESULE;
    swapcontext(&schdule->main, &cor->ctx);
    return OK;
}

unsigned int SaveCoroutineStack(struct Coroutine *cor, char *top)
{
    char stackTop = '\0';
    if (top - &stackTop > STACK_SIZE) {
        return -1;
    }

    unsigned int stackLen = top - &stackTop;
    if (stackLen > cor->cap) {
        free(cor->buf);
        cor->cap = stackLen;
        cor->buf = (char *)malloc(stackLen);
    }

    memcpy(cor->buf, &stackTop, stackLen);
    cor->size = stackLen;
    return OK;
}

unsigned int  YieldCoroutine(struct Schdule *schdule)
{
    unsigned int ret = 0;
    unsigned int runingId = schdule->runingId;
    if (runingId == -1) {
        return OK;
    }

    struct Coroutine *cor = schdule->cors[runingId];
    if ((char *)&cor < schdule->stack) {
        return -1;
    }

    ret = SaveCoroutineStack(cor, schdule->stack + STACK_SIZE);
    if (ret != OK) {
        return -1;
    }
    cor->status = COROUTINE_YIELD;
    schdule->runingId = -1;
    swapcontext(&cor->ctx, &schdule->main);

    return OK;
}