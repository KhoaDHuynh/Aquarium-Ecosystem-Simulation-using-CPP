#ifndef A_TEA
#define A_TEA

#include <string>

/**
 * Each distinct product of a product family should have a base interface. All
 * variants of the product must implement this interface.
 */
class Tea
{
public:
    // ---- DISPLAY METHODS ------------------------------------------------------
    virtual std::string getDescription()    const = 0;      
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----

    // ---- DESTRUCTOR -----------------------------------------------------------
    virtual ~Tea() {};
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----
};

#endif