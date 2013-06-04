#pragma once

#include <thread>

class JobManager;

class JobThread
{
private:
	bool m_running;
	std::thread *m_thread;

	JobManager *m_manager;

public:
	JobThread(JobManager *);
	~JobThread(void);

	void loop();

	void shutdown();
};

