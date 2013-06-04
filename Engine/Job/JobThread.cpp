#include "JobThread.h"

#include "JobManager.h"
#include "Job.h"

#include <pthread.h>

JobThread::JobThread(JobManager *manager) : m_running(true), m_thread(nullptr), m_manager(manager)
{
    m_thread = new std::thread(&JobThread::loop, this);
}


JobThread::~JobThread(void)
{
	if (m_thread) delete m_thread;
}

void JobThread::loop()
{
	while (m_running)
	{
		Job *work = m_manager->fetchJob();
		if (work)
		{

		}
		else
		{
			std::this_thread::yield();
		}
	}
}

void JobThread::shutdown()
{
	m_running = false;
	m_thread->join();
}