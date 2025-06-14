#include <iostream>
#include "../include/Coffee.h"
#include "../include/PlainCoffee.h"
#include "../include/MilkDecorator.h"
#include "../include/SugarDecorator.h"


int main() {
    // Create a plain coffee
    Coffee* plain_one = new PlainCoffee();
    std::cout << "Order: "        << plain_one->getDescription() 
              << "\t\t, Cost: $"  << plain_one->getCost()
              << endl;

    // Wrap it with MilkDecorator
    Coffee* milk_one = new MilkDecorator(plain_one);
    std::cout << "Order: "      << milk_one->getDescription() 
              << "\t, Cost: $"  << milk_one->getCost()
              << endl;

    // Wrap it with SugarDecorator
    Coffee* sugar_one = new SugarDecorator(plain_one);
    std::cout << "Order: "      << sugar_one->getDescription() 
              << "\t, Cost: $"  << sugar_one->getCost()
              << endl;

    Coffee* mixed_one = new SugarDecorator(milk_one);
    std::cout << "Order: "      << mixed_one->getDescription() 
              << "\t, Cost: $"  << mixed_one->getCost()
              << endl;
    
    // Delete the objects
    delete sugar_one;
    delete milk_one;
    delete plain_one;
    delete mixed_one;
}