#ifndef COROUTINE_H_
#define COROUTINE_H_

#define ERROR (-1)
#define OK (0)

typedef enum {
    COROUTINE_READY,
    COROUTINE_RESULE,
    COROUTINE_YIELD,
    COROUTINE_DEAD,
    COROUTINE_BUFF,
} CoroutineStatus;

struct Schdule;

typedef void (*COROUTINE_FUNC)(struct Schdule *schdule, void *args);

Schdule * CreateCoroutineSchdule();

unsigned int RmvCoroutineScdule(struct Schdule *schdule);

unsigned int ResumeCoroutine(struct Schdule *schdule, unsigned int coroutineId);

unsigned int CreateCoroutine(struct Schdule *schdule, COROUTINE_FUNC func, void *args);

unsigned int YieldCoroutine(struct Schdule *schdule);

unsigned int GetCouroutineStatus(struct Schdule *schdule, unsigned int coroutineId);

unsigned int GetRuningId(struct Schdule *schdule);

void PrintInfo(struct Schdule *);

#endif