#include "Camouflage.h"
#include <iostream>

Camouflage::Camouflage(Bestiole*b, double camo)
    : BestioleDecorator(b), camouflageValue(camo)
{ }

Camouflage::~Camouflage() { }

double Camouflage::getCamouflage() const {
    double baseCamo = bestiole->getCamouflage();
    return (camouflageValue > baseCamo) ? camouflageValue : baseCamo;
}

void Camouflage::draw(UImg & support) {
    // Draw the underlying bestiole first.
    bestiole->draw(support);

    // Retrieve the bestiole's position.
    int x = bestiole->getX();
    int y = bestiole->getY();

    // Get the camouflage effectiveness (assumed to be between 0 and 1).
    // Here, a higher value means the bestiole is more camouflaged.
    double psi = getCamouflage();

    // Compute an overlay color that is closer to white.
    // For example, we blend between a very light gray and white.
    // When psi is 0, the overlay is a bit darker (say 230) and when psi is 1, it is almost white (250).
    T overlayColor[3] = {
        static_cast<T>(250 - (20 * (1 - psi))),
        static_cast<T>(250 - (20 * (1 - psi))),
        static_cast<T>(250 - (20 * (1 - psi)))
    };

    // Define the size for the overlay ellipse.
    // We assume the bestiole size is similar to Bestiole::AFF_SIZE (which is 8.0).
    const double size = 8.0;

    // Draw a semi-transparent ellipse over the bestiole.
    // The angle is set to match the bestiole's orientation.
    // The last parameter (e.g., 0.4f) sets the opacity of the overlay.
    support.draw_ellipse(x, y, size, size / 5.0, -bestiole->getOrientation() * 180.0 / M_PI, overlayColor, 0.4f);
}
