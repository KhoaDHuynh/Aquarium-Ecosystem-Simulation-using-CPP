#ifndef COFFEEDECORATOR_H
#define COFFEEDECORATOR_H

#include "Coffee.h"

class CoffeeDecorator : public Coffee {
protected:
    Coffee* coffee;
public:
    CoffeeDecorator(Coffee* c);
    virtual ~CoffeeDecorator();

    // Still purely virtual to force derived decorators to implement them
    virtual std::string getDescription() const = 0;
    virtual double getCost() const = 0;
};

#endif
