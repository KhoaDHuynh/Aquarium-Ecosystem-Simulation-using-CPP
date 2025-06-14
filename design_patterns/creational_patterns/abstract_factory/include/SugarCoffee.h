#ifndef _SUGARCOFFEE_H
#define _SUGARCOFFEE_H

#include <string>
#include "Coffee.h"

class SugarCoffee : public Coffee
{
public:
    std::string getDescription() const override
    {
        return "Order 1 sugar coffee.";
    }
};
#endif