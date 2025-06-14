#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include "Observer.h"

// Observer interface
class Observer 
{
public:
    virtual void update(float temperature, float humidity, float pressure) = 0;
};

#endif