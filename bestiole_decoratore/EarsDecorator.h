#ifndef EARSDECORATOR_H
#define EARSDECORATOR_H

#include "BestioleDecorator.h"

class EarsDecorator : public BestioleDecorator {
private:
    double hearingRange;
    double detectionCap;
public:
    EarsDecorator(Bestiole*b, double range, double cap);
    virtual ~EarsDecorator();

    virtual bool jeTEntends(const Bestiole & b) const override;
};

#endif