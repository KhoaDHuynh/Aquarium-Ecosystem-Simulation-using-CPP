#ifndef _VIHICLETEMPLATE_H_
#define _VIHICLETEMPLATE_H_

#include <iostream>

// Step 1: Template Method (Abstract Class)
class VehicleTemplate 
{
public:
    // Template method defines the algorithm structure
    void buildVehicle() 
    {
        assembleBody();
        installEngine();
        addWheels();
        std::cout << "Vehicle is ready!\n";
    }

    // Abstract methods to be implemented by concrete classes
    virtual void assembleBody() = 0;
    virtual void installEngine() = 0;
    virtual void addWheels() = 0;
};
    
#endif