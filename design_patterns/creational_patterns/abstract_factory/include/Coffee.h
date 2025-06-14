#ifndef A_COFFEE
#define A_COFFEE

#include <string>

/**
 * Each distinct product of a product family should have a base interface. All
 * variants of the product must implement this interface.
 */
class Coffee
{
public:
    // ---- DISPLAY METHODS ------------------------------------------------------
    virtual std::string getDescription()    const = 0;      
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----

    // ---- DESTRUCTOR -----------------------------------------------------------
    virtual ~Coffee() {};
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----
};

#endif