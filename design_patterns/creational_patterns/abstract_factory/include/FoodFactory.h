#ifndef _FOODFACTORY_H_
#define _FOODFACTORY_H_

#include "Coffee.h"
#include "Tea.h"

class FoodFactory
{
public:
    virtual Coffee* createCoffee()  const = 0;
    virtual Tea*    createTea()     const = 0;
};  
#endif