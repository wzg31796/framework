/* Copyright(C)
* For free
* All right reserved
* 
*/
/**
* @file CRealJob.h
* @brief 具体的任务类
* @author highway-9, 787280310@qq.com
* @version 1.1.0
* @date 2016-02-20
*/

#ifndef _CREALJOB_H
#define _CREALJOB_H

#include "CJob.h"
#include <functional>

typedef std::function<void (void*)> OnDoTask;

/**
* @brief 任务类，继承自CJob
*/
class CRealJob : public CJob
{
public:
    CRealJob(OnDoTask func, void* jobData);
    virtual ~CRealJob();

    /**
    * @brief run 执行任务
    */
    virtual void run();

private:
    OnDoTask m_doTask;
    void* m_jobData;
};

typedef std::shared_ptr<CRealJob> CRealJobPtr;

#endif
