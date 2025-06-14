#include "EarsDecorator.h"
#include <cmath>
#include <iostream>

EarsDecorator::EarsDecorator(Bestiole* b, double range, double cap)
    : BestioleDecorator(b), hearingRange(range), detectionCap(cap) 
{ }

EarsDecorator::~EarsDecorator() { }

bool EarsDecorator::jeTEntends(const Bestiole & b) const {
    // Get position
    int x0 = bestiole->getX();
    int y0 = bestiole->getY();

    // Compute the vector from this bestiole to target b
    int bx = b.getX();
    int by = b.getY();
    double dx = bx - x0;
    double dy = by - y0;
    double distance = sqrt(dx * dx + dy * dy);

    // Check distance limits
    if (distance > hearingRange)
        return false;

    // Detection is successful if our sensor's capacity exceeds target's camouflage
    if (detectionCap > b.getCamouflage()) {
        std::cout << "[Ears] detected bestiol at: (" << bx << "," << by << ")" << std::endl;
        return true;
    }
    return false;
}