#pragma once

#include <thread>

class JobManager;

class JobThread
{
private:
	bool m_running;
	std::thread *m_thread;
	JobManager *m_manager;

    // This allows the loop function to be set private
    friend class std::thread;
    void loop();
    
public:
	JobThread(JobManager *);
	~JobThread(void);

	void shutdown();
};

