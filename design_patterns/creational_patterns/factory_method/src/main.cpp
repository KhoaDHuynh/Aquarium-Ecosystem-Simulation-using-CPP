#include "../include/PizzaFactory.h"
#include <iostream>
using namespace std;

int main()
{
    PizzaFactory factory;
    auto hammushroom_one = factory.createPizza(PizzaFactory::HamMushroom);
    auto deluxe_one      = factory.createPizza(PizzaFactory::Deluxe);
    auto seafood_one     = factory.createPizza(PizzaFactory::Seafood);

    cout << hammushroom_one->getPrice() << endl;
    cout << deluxe_one->getPrice()      << endl;
    cout << seafood_one->getPrice()     << endl;

    return 0;
}