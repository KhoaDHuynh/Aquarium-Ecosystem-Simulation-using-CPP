#include "Coffee.h"

int main(int argc, char* argv[]) {

    Coffee* coffee = new PlainCoffee();

    coffee->get_description();
    coffee->get_price();

    coffee = new Milk(coffee);

    coffee->get_description();
    coffee->get_price();

    coffee = new Sugar(coffee);

    coffee->get_description();
    coffee->get_price();

    delete coffee;

    return 0;
}