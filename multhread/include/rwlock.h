#ifndef R_W_LOCK_
#define R_W_LOCK_
#include <mutex>
#include <condition_variable>


class RWLock {
public:
    RWLock() : m_readLockCount(0), m_writeLockCount(0), m_isWriting(false) {}
    ~RWLock() {}
    void ReadLock();
    void ReadUnlock();

    void WriteLock();
    void WriteUnlock();

private:
    RWLock(const RWLock&) = delete;
    RWLock& operator=(const RWLock&) = delete;

private:
    std::mutex m_rwlock;
    std::condition_variable m_rlock_conv;
    std::condition_variable m_wlock_conv;
    int m_readLockCount;
    int m_writeLockCount;
    bool m_isWriting;
};

class ReadLockGuard {
public:
    ReadLockGuard(RWLock& rwlock);
    ~ReadLockGuard();

private:
    ReadLockGuard(const ReadLockGuard&) = delete;
    ReadLockGuard& operator=(const ReadLockGuard&) = delete;

    RWLock& m_rwlock;

};

class WriteLockGuard {
public:
    WriteLockGuard(RWLock& rwlock);
    ~WriteLockGuard();

private:
    WriteLockGuard(const WriteLockGuard&) = delete;
    WriteLockGuard& operator=(const WriteLockGuard&) = delete;

    RWLock& m_rwlock;

};
#endif