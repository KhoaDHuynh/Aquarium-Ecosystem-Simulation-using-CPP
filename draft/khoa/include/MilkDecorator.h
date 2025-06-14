/* ==== H_MILK_DECORATOR =======================================================
    Header file MilkDecorator class.
    Concrete Decorator class for Decorator Pattern.

    Written by:  GROUP-5
    Date:        28/02/2025
================================================================================*/ 

#ifndef H_MILL_DECORATOR
#define H_MILL_DECORATOR

#include "CoffeeDecorator.h"

class MilkDecorator : public CoffeeDecorator
{
public:
    double milk_amout;
    // ---- CONSTRUCTOR ----------------------------------------------------------
    MilkDecorator(std::unique_ptr<Coffee> cafe) : CoffeeDecorator(std::move(cafe)) 
    {
        this->id = 2;
        milk_amout = 100.0;
        cout << "call constructor MilkDecorator" << endl;
    };
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----

    // ---- DISPLAY METHODS ------------------------------------------------------
    string  getDescription() const override {
        cout << "amount of milk: " << milk_amout << endl;
        return coffee->getDescription()
                        + " with Milk";
    }

    double  getCost()       const override {
        return coffee->getCost()
                        + 2.0;
    }
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----  
    ~MilkDecorator() 
    {
        cout << "call destructor MilkDecorator" << endl;
    };

    unique_ptr<Coffee> clone() const override 
    {
        return make_unique<MilkDecorator>(coffee->clone()); // Implement clone method
    }
};
#endif