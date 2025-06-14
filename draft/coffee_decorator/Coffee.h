#ifndef COFFEE_H
#define COFFEE_H

#include <string>

class Coffee {
public:
    virtual ~Coffee() {}
    virtual std::string getDescription() const = 0;
    virtual double getCost() const = 0;
};

#endif
