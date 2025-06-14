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
    double sugar_amout = 50.0;
    // ---- CONSTRUCTOR ----------------------------------------------------------
    SugarDecorator(std::unique_ptr<Coffee> cafe) : CoffeeDecorator(std::move(cafe)) 
    {
        this->id = 3;
        cout << "call constructor SugarDecorator" << endl;
    };
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----

    // ---- DISPLAY METHODS ------------------------------------------------------
    string  getDescription() const override {
        cout << "amount of sugar: " << sugar_amout << endl;
        return coffee->getDescription()
                        + " with Sugar";
    }

    double  getCost()       const override {
        return coffee->getCost()
                        + 1.0;
    }
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----  
    ~SugarDecorator() 
    {
        cout << "call destructor SugarDecorator" << endl;
    };

    unique_ptr<Coffee> clone() const override {
        return make_unique<SugarDecorator>(coffee->clone()); // Implement clone method
    }
};
#endif