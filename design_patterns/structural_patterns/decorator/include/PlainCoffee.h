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
    // ---- DISPLAY METHODS ------------------------------------------------------
    std::string getDescription()    const override { return "Plain Coffee"; }
    double      getCost()           const override { return 10.0; }
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----
};

#endif
