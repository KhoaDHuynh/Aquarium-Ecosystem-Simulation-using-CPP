#include "../include/WeatherStation.h"
#include "../include/Display.h"

int main() 
{
    WeatherStation weatherStation;

    // Create displays
    Display display1;
    Display display2;

    // Register displays as observers
    weatherStation.registerObserver(&display1);
    weatherStation.registerObserver(&display2);

    // Simulate weather data updates
    weatherStation.setMeasurements(25.5, 60, 1013.2);
    weatherStation.setMeasurements(24.8, 58, 1014.5);

    return 0;
}