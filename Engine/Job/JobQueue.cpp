#include "JobQueue.h"


namespace Inertia {

JobQueue::JobQueue()
{
    m_queue = new std::priority_queue<Job*>();
}


JobQueue::~JobQueue()
{
    delete m_queue;
}


void JobQueue::addJob(Job *job)
{
    m_lock.lock();
    m_queue->push(job);
    m_lock.unlock();
}



Job* JobQueue::removeJob()
{
    Job *job = nullptr;
    
    m_lock.lock();
    if (! m_queue->empty())
    {
        job = m_queue->top();
        m_queue->pop();
    }
    m_lock.unlock();
    
    return job;
}

}