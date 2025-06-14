#include <iostream>
#include <vector>
using namespace std;

#include "../include/Car.h"
#include "../include/Motorcycle.h"

int main()
{
    // Build a Car
    std::cout << "Building a Car:\n";
    Car car;
    car.buildVehicle();

    // Build a Motocycle
    std::cout << "\nBuilding a Motorcycle:\n";
    Motorcycle motorcycle;
    motorcycle.buildVehicle();

    return 0;
}
