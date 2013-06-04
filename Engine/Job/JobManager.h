#pragma once

#include "JobQueue.h"
#include "JobThread.h"

#include <list>

class JobManager {
private:
    JobQueue *m_jobs;
    std::list<JobThread*> *m_threads;
    
public:
    JobManager();
    ~JobManager();
    
    void Initialize(int threads);
    void Shutdown();
    
    void submitJob(Job *);
    
    Job* fetchJob();
};