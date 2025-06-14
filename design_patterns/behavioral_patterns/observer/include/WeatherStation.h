#ifndef _WEATHERSTATION_H_
#define _WEATHERSTATION_H_

#include <iostream>
#include <vector>

#include "Observer.h"

// Subject (WeatherStation) class
class WeatherStation {
private:
    float temperature;
    float humidity;
    float pressure;
    std::vector<Observer*> observers;

public:
    void registerObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        // You can implement the removal logic if needed.
    }

    void notifyObservers() {
        for (Observer* observer : observers) {
            observer->update(temperature, humidity, pressure);
        }
    }

    void setMeasurements(float temp, float hum, float press) {
        temperature = temp;
        humidity = hum;
        pressure = press;
        notifyObservers();
    }
};
#endif