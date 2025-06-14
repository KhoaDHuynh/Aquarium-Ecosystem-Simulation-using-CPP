#ifndef _MOTORCYCLE_H_
#define _MOTORCYCLE_H_

#include "VehicleTemplate.h"

class Motorcycle : public VehicleTemplate 
{
public:
    void assembleBody() override 
    {
        std::cout << "Assembling motorcycle frame.\n";
    }

    void installEngine() override 
    {
        std::cout << "Installing motorcycle engine.\n";
    }

    void addWheels() override 
    {
        std::cout << "Adding 2 wheels to the motorcycle.\n";
    }
};

#endif