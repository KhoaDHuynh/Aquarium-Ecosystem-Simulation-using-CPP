#ifndef _COOK_H_
#define _COOK_H_

#include "PizzaBuilder.h"

// Director class that orchestrates the construction
class Cook 
{
public:
    void makePizza(PizzaBuilder& builder)
    {
        builder.buildDough();
        builder.buildSauce();
        builder.buildTopping();
    }
};

#endif