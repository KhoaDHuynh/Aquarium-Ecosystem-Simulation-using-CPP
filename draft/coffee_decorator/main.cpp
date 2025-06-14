#include <iostream>
#include "PlainCoffee.h"
#include "MilkDecorator.h"
#include "SugarDecorator.h"

int main() {
    // Start with a plain coffee
    Coffee* myCoffee = new PlainCoffee();
    std::cout << myCoffee->getDescription() 
              << " costs " << myCoffee->getCost() << std::endl;

    // Decorate with milk
    myCoffee = new MilkDecorator(myCoffee);
    std::cout << myCoffee->getDescription() 
              << " costs " << myCoffee->getCost() << std::endl;

    // Decorate with sugar
    myCoffee = new SugarDecorator(myCoffee);
    std::cout << myCoffee->getDescription() 
              << " costs " << myCoffee->getCost() << std::endl;

    // Clean up
    delete myCoffee;

    return 0;
}
