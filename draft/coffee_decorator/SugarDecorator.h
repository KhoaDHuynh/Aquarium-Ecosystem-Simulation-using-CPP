#ifndef SUGARDECORATOR_H
#define SUGARDECORATOR_H

#include "CoffeeDecorator.h"

class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(Coffee* c);
    virtual std::string getDescription() const;
    virtual double getCost() const;
};

#endif
