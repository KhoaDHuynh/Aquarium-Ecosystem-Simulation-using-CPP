#ifndef _MILKFACTORY_H_
#define _MILKFACTORY_H_

#include "FoodFactory.h"
#include "MilkCoffee.h"
#include "MilkTea.h"

class MilkFactory : public FoodFactory
{
public:
    Coffee* createCoffee()  const override
    {
        return new MilkCoffee();
    };

    Tea*    createTea()     const override
    {
        return new MilkTea();
    };

    ~MilkFactory() {};
};  
#endif