#include "JobManager.h"
#include "JobQueue.h"


namespace Inertia {

JobManager::JobManager() : m_jobs(nullptr)
{
    m_jobs = new JobQueue();
    m_threads = new std::list<JobThread*>();
}

JobManager::~JobManager()
{
    delete m_jobs;
    delete m_threads;
}

void JobManager::Initialize(int threads)
{
    for (int i =0; i < threads; i++)
    {
        m_threads->push_back(new JobThread(this));
    }
}

void JobManager::Shutdown()
{
    for (auto thread : *m_threads)
    {
        thread->shutdown();
        delete thread;
    }
}

void JobManager::submitJob(Job *job)
{
    m_jobs->addJob(job);
}

Job* JobManager::fetchJob()
{
    return m_jobs->removeJob();
}

}