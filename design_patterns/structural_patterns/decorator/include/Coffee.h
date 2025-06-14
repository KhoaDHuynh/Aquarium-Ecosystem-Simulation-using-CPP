/* ==== I_COFFEE ================================================================
    Interface for the Coffee class

    Written by:  GROUP-5
    Date:        28/02/2025
================================================================================*/ 

#ifndef I_COFFEE
#define I_COFFEE

#include <string>

class Coffee
{
public:
    // ---- DISPLAY METHODS ------------------------------------------------------
    /*
        -  "const" indicates that the member function does not modify the state of 
        the object.
        - "=0" specifies that the function is a pure virtual function. A pure virtual 
        function does not have an implementation in the base class and must be 
        overridden by derived classes. 
        - Declaring a function as pure virtual makes the class abstract, meaning 
        it cannot be instantiated directly.
    */
    virtual std::string getDescription()    const = 0;      
    virtual double      getCost()           const = 0;
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----

    // ---- DESTRUCTOR -----------------------------------------------------------
    virtual ~Coffee() {};
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----
};

#endif