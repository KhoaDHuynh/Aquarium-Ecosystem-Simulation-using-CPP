#ifndef EYESDECORATOR_H
#define EYESDECORATOR_H

#include "BestioleDecorator.h"

class EyesDecorator : public BestioleDecorator {
private:
    double fieldOfView;
    double deltaMin;
    double deltaMax;
    double detectionCap;
public:
    EyesDecorator(Bestiole*b, double fov, double dMin, double dMax, double cap);
    virtual ~EyesDecorator();

    virtual bool jeTeVois(const Bestiole & b) const override;
};

#endif