#ifndef _TRAFFICLIGHT_H_
#define _TRAFFICLIGHT_H_

#include "TrafficLightState.h"
#include "RedState.h"

// Context
class TrafficLight {
    private:
        TrafficLightState *state;
    
    public:
        TrafficLight() : state(new RedState()) {}
    
        void setState(TrafficLightState *newState) {
            delete state;
            state = newState;
        }
    
        void change() {
            state->handle();
        }
    };

#endif