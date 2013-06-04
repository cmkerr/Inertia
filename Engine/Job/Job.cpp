#include "Job.h"

bool operator< (Job& j1, Job& j2)
{
    return j1.priority < j2.priority;
}