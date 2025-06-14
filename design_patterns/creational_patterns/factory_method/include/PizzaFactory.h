#ifndef _PIZZAFACTORY_H_
#define _PIZZAFACTORY_H_

#include "IPizza.h"
#include "HamAndMushroomPizza.h"
#include "DeluxePizza.h"
#include "SeafoodPizza.h"

#include <memory>
using namespace std;

class PizzaFactory
{
public:
    enum PizzaType {HamMushroom, Deluxe, Seafood};
    
    unique_ptr<IPizza> createPizza(PizzaType _pizzatype);
};

#endif