/* ==== I_COFFEE ================================================================
    Interface for the Coffee class

    Written by:  GROUP-5
    Date:        28/02/2025
================================================================================*/ 

#ifndef I_COFFEE
#define I_COFFEE

#include <string>
#include <iostream>
using namespace std;

class Coffee
{
public:
    int id = 0;
    static int counter;

    Coffee() 
    {
        id = 0;
        cout << "call constructor Coffee" << endl;
    }
    // ---- DISPLAY METHODS ------------------------------------------------------
    virtual std::string getDescription()    const = 0;
    virtual double      getCost()           const = 0;
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----

    // ---- DESTRUCTOR -----------------------------------------------------------
    virtual ~Coffee() 
    {
        cout << "call destructor Coffee" << endl;
    };
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----
    virtual unique_ptr<Coffee> clone() const = 0; // Add clone method
};

int Coffee::counter = 0;

#endif