#ifndef PLAINCOFFEE_H
#define PLAINCOFFEE_H

#include "Coffee.h"

class PlainCoffee : public Coffee {
public:
    PlainCoffee();
    virtual std::string getDescription() const;
    virtual double getCost() const;
};

#endif
