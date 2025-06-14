#include "CoffeeDecorator.h"

CoffeeDecorator::CoffeeDecorator(Coffee* c) : coffee(c) {
}

CoffeeDecorator::~CoffeeDecorator() {
    // Delete the wrapped coffee to avoid memory leaks
    delete coffee;
}
