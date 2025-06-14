#ifndef MILKDECORATOR_H
#define MILKDECORATOR_H

#include "CoffeeDecorator.h"

class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(Coffee* c);
    virtual std::string getDescription() const;
    virtual double getCost() const;
};

#endif
