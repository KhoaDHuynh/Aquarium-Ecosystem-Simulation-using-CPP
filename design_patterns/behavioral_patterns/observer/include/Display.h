#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <iostream>
#include "Observer.h"

// Concrete Observer
class Display : public Observer 
{
public:
    void update(float temperature, float humidity, float pressure) 
    {
        std::cout << "Display: Temperature = " << temperature
                    << "°C, Humidity = "       << humidity
                    << "%, Pressure = "        << pressure << " hPa"
                    << std::endl;
    }
};

#endif
