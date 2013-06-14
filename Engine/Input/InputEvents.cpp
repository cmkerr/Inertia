#include "InputEvents.h"

namespace Inertia {

bool operator== (const Input& i1, const Input& i2)
{
    return i1.event == i2.event && i1.action == i2.action;
}
    
bool operator< (const Input& i1, const Input& i2)
{
    if (i1.event == i2.event)
        return i1.action < i2.action;
    else
        return i1.event < i2.event;
}

}