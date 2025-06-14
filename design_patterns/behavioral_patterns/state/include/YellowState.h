#ifndef _YELLOWSTATE_H_
#define _YELLOWSTATE_H_

#include <iostream>
#include "TrafficLightState.h"

class YellowState : public TrafficLightState {
public:
    void handle() override {
        std::cout << "Traffic Light is Yellow\n";
    }
};
    
#endif