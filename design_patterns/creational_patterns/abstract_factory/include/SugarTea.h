#ifndef _SUGARTEA_H
#define _SUGARTEA_H

#include <string>
#include "Tea.h"

class SugarTea : public Tea
{
public:
    std::string getDescription() const override
    {
        return "Order 1 sugar tea.";
    }
};
#endif