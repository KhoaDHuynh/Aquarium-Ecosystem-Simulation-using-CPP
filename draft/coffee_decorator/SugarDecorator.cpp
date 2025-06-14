#include "SugarDecorator.h"

SugarDecorator::SugarDecorator(Coffee* c) : CoffeeDecorator(c) {
}

std::string SugarDecorator::getDescription() const {
    return coffee->getDescription() + ", Sugar";
}

double SugarDecorator::getCost() const {
    return coffee->getCost() + 0.2;
}
