/* ==== H_COFFEE_DECORATOR =====================================================
    Header file for CoffeeDecorator class - the base class for all coffee 
    decorators.
    Abstract Decorator class for Decorator Pattern.

    Written by:  GROUP-5
    Date:        28/02/2025
================================================================================*/ 

#ifndef H_COFFEE_DECORATOR
#define H_COFFEE_DECORATOR


#include <string>
#include "Coffee.h"
using namespace std; 

class CoffeeDecorator : public Coffee
{ 
protected:
    Coffee *coffee;
public:
    // ---- CONSTRUCTOR ----------------------------------------------------------
    CoffeeDecorator(Coffee* cafe) : coffee(cafe) {};
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----

    // ---- DISPLAY METHODS ------------------------------------------------------
    string  getDescription() const override {
        return coffee->getDescription();
    }
    double  getCost()       const override {
        return coffee->getCost();
    }
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----
};

#endif