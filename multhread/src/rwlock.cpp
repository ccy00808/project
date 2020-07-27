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

void HRowConversionL(int **table, int len, int row, int low, int& val)
{
    int tmp = val;
    val = *(*(table + row) + len - low - 1);
    *(*(table + row) + len - low - 1) = tmp;
}

void RLConversionRow(int **table, int len, int row, int low, int& val)
{
    int tmp = val;
    val = *(*(table + len - 1 - low) + len - 1 - low);
    *(*(table + len - 1 - low) + len - 1 - low) = tmp;
}

void LLConversionLeft(int **table, int len, int row, int low, int& val)
{
    int tmp = val;
    val = *(*(table + len - row) + low);
    *(*(table + len - row) + low) = tmp;

}

void LLConversionHRow(int **table, int len, int row, int low, int& val)
{
    *(*(table + row) + low) = val;
}


int** GetCircle90Table(int **table, int len)
{
    for (int i = 0; i < len; ++i) {
        for (int j = i; j < len - i; ++j) {
            int tmp = *(*(table + i) + j);
            HRowConversionL(table, len, i, j, tmp);
            RLConversionRow(table, len, i, j, tmp);
            LLConversionLeft(table, len, i, j, tmp);
            LLConversionHRow(table, len, i, j, tmp);
        }
    }
    return table;
}