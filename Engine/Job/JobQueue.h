#pragma once

#include "Job.h"

#include <queue>
#include <thread>

class JobQueue {
private:
    std::priority_queue<Job*> *m_queue;
    std::mutex m_lock;
    
public:
    JobQueue();
    ~JobQueue();
    
    void addJob(Job*);
    Job* removeJob();
};