#include "../include/Cook.h"
#include "../include/HawaiianPizzaBuilder.h"
#include "../include/SpicyPizzaBuilder.h"

int main()
{
    Cook cook;

    // create Hawiian Pizza
    HawaiianPizzaBuilder hawaiianBuilder;
    cook.makePizza(hawaiianBuilder);
    Pizza hawaiianPizza = hawaiianBuilder.getPizza();
    hawaiianPizza.displayPizza();

    // Create Spicy Pizza
    SpicyPizzaBuilder spicyBuilder;
    cook.makePizza(spicyBuilder);
    Pizza spicyPizza = spicyBuilder.getPizza();
    spicyPizza.displayPizza();

    return 0;
}