#include "Coffee.h"
#include <iostream>

double Coffee::up_price() const {
    return price;
};

void Coffee::get_price() const {
    std::cout << "Price: " << price << std::endl;
};

Coffee::~Coffee() {};

PlainCoffee::PlainCoffee() { 
    price = 2.0;
} 

void PlainCoffee::get_description() const {
    std::cout << "Plain coffee" << std::endl;
};

CoffeeDecorator::CoffeeDecorator(Coffee* coffee, double extraCost) : coffee(coffee) {
    price = coffee->up_price() + extraCost; 
};

CoffeeDecorator::~CoffeeDecorator() {
    delete coffee;
};

Sugar::Sugar(Coffee* coffee) : CoffeeDecorator(coffee, 0.5) {};

void Sugar::get_description() const {
    coffee->get_description();
    std::cout << " + sugar" << std::endl;
};


Milk::Milk(Coffee* coffee) : CoffeeDecorator(coffee, 0.3) {};

void Milk::get_description() const {
    coffee->get_description();
    std::cout << " + milk" << std::endl;
};







