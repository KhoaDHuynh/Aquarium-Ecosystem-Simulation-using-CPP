#include "Nageoires.h"
#include <iostream>

Nageoires::Nageoires(Bestiole*b, double multiplier) 
    : BestioleDecorator(b), speedMultiplier(multiplier) 
{ 
    double originalSpeed = bestiole->getVitesse();
    double boostedSpeed = originalSpeed * speedMultiplier;
    bestiole->setVitesse(boostedSpeed);
    std::cout << "[Nageoires] speed increased from " << originalSpeed << " to " << bestiole->getVitesse() << std::endl;


}

Nageoires::~Nageoires() { }

void Nageoires::action(Milieu & monMilieu) {
    bestiole->action(monMilieu);
}