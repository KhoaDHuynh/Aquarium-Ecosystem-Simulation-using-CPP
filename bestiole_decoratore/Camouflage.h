#ifndef CAMOUFLAGE_H
#define CAMOUFLAGE_H

#include "BestioleDecorator.h"

class Camouflage : public BestioleDecorator {
    private:
        double camouflageValue;
    public:
        Camouflage(Bestiole*b, double camo);
        virtual ~Camouflage();

        virtual double getCamouflage() const override;

        virtual void draw(UImg & support) override;
};

#endif