#ifndef _REDSTATE_H_
#define _REDSTATE_H_

#include <iostream>
#include "TrafficLightState.h"

// Concrete States
class RedState : public TrafficLightState {
public:
    void handle() override {
        std::cout << "Traffic Light is Red\n";
    }
};

#endif