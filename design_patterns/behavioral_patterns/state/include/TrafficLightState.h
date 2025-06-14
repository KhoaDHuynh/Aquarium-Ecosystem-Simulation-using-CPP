#ifndef _TRAFFICLIGHTSTATE_H_
#define _TRAFFICLIGHTSTATE_H_

// State Interface
class TrafficLightState 
{
public:
    virtual void handle() = 0;
    virtual ~TrafficLightState() {}
};
    
#endif