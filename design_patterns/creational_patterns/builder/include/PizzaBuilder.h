#ifndef _PIZZABUILDER_H_
#define _PIZZABUILDER_H_

#include "Pizza.h"

// Abstract builder class
class PizzaBuilder 
{
public:
    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;
    
    virtual Pizza getPizza() const = 0;
};

#endif