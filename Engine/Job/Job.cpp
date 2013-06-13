#include "Job.h"


namespace Inertia {

bool operator< (Job& j1, Job& j2)
{
    return j1.priority < j2.priority;
}

}