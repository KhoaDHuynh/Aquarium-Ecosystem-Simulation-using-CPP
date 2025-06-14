#ifndef _SPICYPIZZABUILDER_H_
#define _SPICYPIZZABUILDER_H_

#include "PizzaBuilder.h"

// Concrete builder for another type of pizza
class SpicyPizzaBuilder : public PizzaBuilder 
{
private:
    Pizza pizza;
    
public:
    void buildDough() override
    {
        pizza.setDough("Thin Dough");
    }

    void buildSauce() override
    {
        pizza.setSauce("Spicy Tomato Sauce");
    }

    void buildTopping() override
    {
        pizza.setTopping("Pepperoni and Jalapenos");
    }

    Pizza getPizza() const override { return pizza; }
};

#endif