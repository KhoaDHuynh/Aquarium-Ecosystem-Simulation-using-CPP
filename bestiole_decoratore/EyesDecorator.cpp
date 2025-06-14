#include "EyesDecorator.h"
#include <cmath>
#include <iostream>

EyesDecorator::EyesDecorator(Bestiole* b, double fov, double dMin, double dMax, double cap)
    : BestioleDecorator(b), fieldOfView(fov), deltaMin(dMin), deltaMax(dMax), detectionCap(cap) 
{ }

EyesDecorator::~EyesDecorator() { }

bool EyesDecorator::jeTeVois(const Bestiole & b) const {
    // Get position and orientation
    int x0 = bestiole->getX();
    int y0 = bestiole->getY();
    double orient = bestiole->getOrientation();

    // Compute the vector from this bestiole to target b
    int bx = b.getX();
    int by = b.getY();
    double dx = bx - x0;
    double dy = by - y0;
    double distance = sqrt(dx * dx + dy * dy);

    // Check distance limits
    if (distance < deltaMin || distance > deltaMax)
        return false;

    // Compute the angle to the target
    double angleToB = atan2(-dy, dx);
    double angleDiff = fabs(orient - angleToB);
    if (angleDiff > M_PI)
        angleDiff = 2 * M_PI - angleDiff;

    // Target must be within half the field of view 
    if (angleDiff > fieldOfView /2)
        return false;

    // Detection is successful if our sensor's capacity exceeds target's camouflage
    if (detectionCap > b.getCamouflage()) {
        std::cout << "[Eyes] detected bestiol at: (" << bx << "," << by << ")" << std::endl;
        return true;
    }
    return false;
}