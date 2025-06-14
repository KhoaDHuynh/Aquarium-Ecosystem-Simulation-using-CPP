#ifndef _HAWIIANPIZZABUILDER_H_
#define _HAWIIANPIZZABUILDER_H_

#include "PizzaBuilder.h"

// Concrete builder for a specific type of pizza
class HawaiianPizzaBuilder : public PizzaBuilder 
{
private:
    Pizza pizza;

public:
    void buildDough() override
    {
        pizza.setDough("Pan Dough");
    }

    void buildSauce() override
    {
        pizza.setSauce("Hawaiian Sauce");
    }

    void buildTopping() override
    {
        pizza.setTopping("Ham and Pineapple");
    }

    Pizza getPizza() const override { return pizza; }
};

#endif