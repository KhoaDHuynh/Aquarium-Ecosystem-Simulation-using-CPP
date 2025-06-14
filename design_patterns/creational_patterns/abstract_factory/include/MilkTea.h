#ifndef _MILKTEA_H
#define _MILKTEA_H

#include <string>
#include "Tea.h"

class MilkTea : public Tea
{
public:
    std::string getDescription() const override
    {
        return "Order 1 milk tea.";
    }
};
#endif