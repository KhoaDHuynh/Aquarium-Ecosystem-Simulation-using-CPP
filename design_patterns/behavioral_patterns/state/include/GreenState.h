#ifndef _GREENSTATE_H_
#define _GREENSTATE_H_

#include <iostream>
#include "TrafficLightState.h"

class GreenState : public TrafficLightState {
public:
    void handle() override {
        std::cout << "Traffic Light is Green\n";
    }
};
    
#endif