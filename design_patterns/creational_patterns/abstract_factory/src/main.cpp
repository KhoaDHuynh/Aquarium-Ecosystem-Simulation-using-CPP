#include <iostream>
#include <memory>
#include "../include/FoodFactory.h"
#include "../include/MilkFactory.h"
#include "../include/SugarFactory.h"

/**
 * The client code works with factories and products only through abstract
 * types: AbstractFactory and AbstractProduct. This lets you pass any factory or
 * product subclass to the client code without breaking it.
 */
 void ClientCode(const FoodFactory &factory)
 {
    const Coffee* cafe = factory.createCoffee();
    const Tea*    the  = factory.createTea();

    std::cout << cafe->getDescription() << std::endl;
    std::cout << the->getDescription()  << std::endl;

    delete cafe;    // since the factories fabricated things on the HEAP, therefore we have to clean them
    delete the;
 }

int main() {
    std::cout << "Client: Testing client code with the first factory type" << std::endl;
    MilkFactory* mf = new MilkFactory();
    ClientCode(*mf);        // mf is a pointer, therefore *mf is an object
    delete mf;              // the factory is on the HEAP

    std::cout << "Client: Testing the same client code with the second factory type" << std::endl;
    SugarFactory* sf = new SugarFactory();
    ClientCode(*sf);
    delete sf;
}