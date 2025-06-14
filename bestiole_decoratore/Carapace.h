#ifndef CARAPACE_H
#define CARAPACE_H

#include "BestioleDecorator.h"

class Carapace : public BestioleDecorator {
    private:
        double speedReduction;
        double protectionFactor;
    public:
        Carapace(Bestiole* b, double reduction, double protection);
        virtual ~Carapace();

        virtual void action(Milieu & monMilieu) override;

};

#endif