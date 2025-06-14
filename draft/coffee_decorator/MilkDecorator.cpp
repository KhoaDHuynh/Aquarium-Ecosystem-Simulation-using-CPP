#include "MilkDecorator.h"

MilkDecorator::MilkDecorator(Coffee* c) : CoffeeDecorator(c) {
}

std::string MilkDecorator::getDescription() const {
    return coffee->getDescription() + ", Milk";
}

double MilkDecorator::getCost() const {
    return coffee->getCost() + 0.5;
}
