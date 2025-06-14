/* ==== H_PlainCoffee ==========================================================
    Header file for PlainCoffee class - the base class for all coffee types.
    Concrete Component class for Decorator Pattern. 

    Written by:  GROUP-5
    Date:        28/02/2025
================================================================================*/ 

#ifndef H_PlainCoffee
#define H_PlainCoffee

#include "Coffee.h"
#include <string>

class PlainCoffee : public Coffee
{
public:
    PlainCoffee() 
    { 
        counter++;
        id = 1; 
        cout << "call constructor PlainCoffee" << endl;
    }

    unique_ptr<Coffee> clone() const override 
    {
        return make_unique<PlainCoffee>(*this); // Implement clone method
    }
    // ---- DISPLAY METHODS ------------------------------------------------------
    std::string getDescription()    const override { return "Plain Coffee"; }
    double      getCost()           const override { return 10.0; }
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----
    ~PlainCoffee() 
    {
        cout << "call destructor PlainCoffee" << endl;
    };
};

#endif
