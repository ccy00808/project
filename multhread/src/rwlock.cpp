#include "rwlock.h"

void RWLock::ReadLock()
{
    std::unique_lock<std::mutex> rlock(m_rwlock);
    m_rlock_conv.wait(rlock, [&]{return m_writeLockCount == 0;});
    ++m_readLockCount;
}

void RWLock::ReadUnlock()
{
    std::unique_lock<std::mutex> rlock(m_rwlock);
    m_rlock_conv.wait(rlock, [&]{return m_readLockCount > 0;});
    if (--m_readLockCount == 0) {
        m_wlock_conv.notify_one();
    }
}

void RWLock::WriteLock()
{
    std::unique_lock<std::mutex> wlock(m_rwlock);
    ++m_writeLockCount;
    m_wlock_conv.wait(wlock, [&]{return !m_isWriting && m_readLockCount == 0;});
    m_isWriting = true;
}

void RWLock::WriteUnlock()
{
    std::unique_lock<std::mutex> wlock(m_rwlock);
    if (--m_writeLockCount == 0) {
        m_rlock_conv.notify_one();
        m_isWriting = false;
    } else {
        m_wlock_conv.notify_one();
    }
}

ReadLockGuard::ReadLockGuard(RWLock& rwlock) : m_rwlock(rwlock)
{
    rwlock.ReadLock();
}

ReadLockGuard::~ReadLockGuard()
{
    m_rwlock.ReadUnlock();
}

WriteLockGuard::WriteLockGuard(RWLock& rwlock) : m_rwlock(rwlock)
{
    m_rwlock.WriteLock();
}

WriteLockGuard::~WriteLockGuard()
{
    m_rwlock.WriteUnlock();
}