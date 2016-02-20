/* Copyright(C)
* For free
* All right reserved
* 
*/
/**
* @file CWorkerThread.h
* @brief 工作线程类
* @author highway-9, 787280310@qq.com
* @version 1.1.0
* @date 2016-02-17
*/

#ifndef _CWORKERTHREAD_H
#define _CWORKERTHREAD_H

#include "CThread.h"

class CThreadPool;
class CJob;

class CWorkerThread
        : public CThread,
          public boost::enable_shared_from_this<CWorkerThread>
{
public:
    typedef boost::shared_ptr<CThreadPool> CThreadPoolPtr;
    typedef boost::shared_ptr<CJob> CJobPtr;

    CWorkerThread();
    virtual ~CWorkerThread();

    virtual void run();

    boost::mutex m_workMutex;
    boost::condition_variable_any m_jobCond;

public:
    CThreadPoolPtr threadPool() const;
    void setThreadPool(CThreadPoolPtr threadPool);

    CJobPtr job() const;
    void setJob(CJobPtr job, void* jobData);

private:
    CThreadPoolPtr m_threadPool;
    CJobPtr m_job;
    void* m_jobData;

    boost::mutex m_varMutex;
    bool m_isEnd;
};

typedef boost::shared_ptr<CWorkerThread> CWorkerThreadPtr;

#endif
