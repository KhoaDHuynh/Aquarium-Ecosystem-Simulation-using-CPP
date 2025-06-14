#include "PlainCoffee.h"

PlainCoffee::PlainCoffee() {
    // Constructor can be empty or used for initialization
}

std::string PlainCoffee::getDescription() const {
    return "Plain Coffee";
}

double PlainCoffee::getCost() const {
    return 1.0;
}
