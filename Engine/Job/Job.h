#pragma once

class Job {
public:
    enum Priority {
        Low,
        Medium,
        High
    };
    
    const Priority priority;
    
    Job(Priority a_priority): priority(a_priority) {}
    
    virtual void Run() = 0;
};