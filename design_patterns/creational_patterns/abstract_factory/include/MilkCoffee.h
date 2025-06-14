#ifndef _MILKCOFFEE_H
#define _MILKCOFFEE_H

#include <string>
#include "Coffee.h"

class MilkCoffee : public Coffee
{
public:
    std::string getDescription() const override
    {
        return "Order 1 milk coffee.";
    }
};
#endif