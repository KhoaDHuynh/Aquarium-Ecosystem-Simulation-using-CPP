#ifndef _CAR_H_
#define _CAR_H_

#include "VehicleTemplate.h"

class Car : public VehicleTemplate {
    public:
        void assembleBody() override 
        {
            std::cout << "Assembling car body.\n";
        }
    
        void installEngine() override 
        {
            std::cout << "Installing car engine.\n";
        }
    
        void addWheels() override 
        {
            std::cout << "Adding 4 wheels to the car.\n";
        }
    };

#endif