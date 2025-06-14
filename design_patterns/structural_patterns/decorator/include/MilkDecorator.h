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
    // ---- CONSTRUCTOR ----------------------------------------------------------
    MilkDecorator(Coffee* cafe) : CoffeeDecorator(cafe) {};
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----

    // ---- DISPLAY METHODS ------------------------------------------------------
    string  getDescription() const override {
        return coffee->getDescription()
                        + " with Milk";
    }

    double  getCost()       const override {
        return coffee->getCost()
                        + 2.0;
    }
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----  
};
#endif