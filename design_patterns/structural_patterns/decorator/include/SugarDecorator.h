/* ==== H_SUGAR_DECORATOR ======================================================
    Header file MilkDecorator class.
    Concrete Decorator class for Decorator Pattern.

    Written by:  GROUP-5
    Date:        28/02/2025
================================================================================*/ 

#ifndef H_SUGAR_DECORATOR
#define H_SUGAR_DECORATOR

#include "CoffeeDecorator.h"

class SugarDecorator : public CoffeeDecorator
{
public:
    // ---- CONSTRUCTOR ----------------------------------------------------------
    SugarDecorator(Coffee* cafe) : CoffeeDecorator(cafe) {};
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----

    // ---- DISPLAY METHODS ------------------------------------------------------
    string  getDescription() const override {
        return coffee->getDescription()
                        + " with Sugar";
    }

    double  getCost()       const override {
        return coffee->getCost()
                        + 1.0;
    }
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----  
};
#endif