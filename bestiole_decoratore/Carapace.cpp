#include "Carapace.h"
#include <iostream>

Carapace::Carapace(Bestiole*b, double reduction, double protection)
    : BestioleDecorator(b), speedReduction(reduction), protectionFactor(protection)
{ }

Carapace::~Carapace() { }

void Carapace::action(Milieu & monMilieu) {
    // Temporarily reduce speed due to the extra weight of the shell
    double originalSpeed = bestiole->getVitesse();
    bestiole->setVitesse(originalSpeed / speedReduction);
    std::cout << "[Carapace] speed reduced from " << originalSpeed << " to " << bestiole->getVitesse() << std::endl;
    bestiole->action(monMilieu);
    bestiole->setVitesse(originalSpeed);
}