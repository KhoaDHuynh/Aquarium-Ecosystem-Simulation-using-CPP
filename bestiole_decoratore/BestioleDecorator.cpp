#include "BestioleDecorator.h"

BestioleDecorator::BestioleDecorator(Bestiole* b) : bestiole(b) {
}

BestioleDecorator::~BestioleDecorator() { 
    delete bestiole;
}

void BestioleDecorator::action(Milieu & monMilieu) {
    bestiole->action(monMilieu);
}

void BestioleDecorator::draw(UImg & support) {
    bestiole->draw(support);
}

bool BestioleDecorator::jeTeVois(const Bestiole & b) const {
    return bestiole->jeTeVois(b);
}

bool BestioleDecorator::jeTEntends(const Bestiole & b) const {
    return bestiole->jeTEntends(b);
}

double BestioleDecorator::getCamouflage() const {
    return bestiole->getCamouflage();
}

void BestioleDecorator::initCoords(int xLim, int yLim) {
    bestiole->initCoords(xLim, yLim);
}