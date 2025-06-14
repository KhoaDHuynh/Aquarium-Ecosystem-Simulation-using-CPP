#ifndef _SUGARFACTORY_H_
#define _SUGARFACTORY_H_

#include "FoodFactory.h"
#include "SugarCoffee.h"
#include "SugarTea.h"

class SugarFactory : public FoodFactory
{
public:
    Coffee* createCoffee()  const override
    {
        return new SugarCoffee();
    };

    Tea*    createTea()     const override
    {
        return new SugarTea();
    };

    ~SugarFactory() {};
};  
#endif