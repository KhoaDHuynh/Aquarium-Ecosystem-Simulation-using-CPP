#ifndef NAGEOIRES_H
#define NAGEOIRES_H

#include "BestioleDecorator.h"

class Nageoires : public BestioleDecorator {
    private:
        double speedMultiplier;
    public:
        Nageoires(Bestiole*b, double multiplier);
        virtual ~Nageoires();

        virtual void action(Milieu & monMilieu) override; 
};

#endif