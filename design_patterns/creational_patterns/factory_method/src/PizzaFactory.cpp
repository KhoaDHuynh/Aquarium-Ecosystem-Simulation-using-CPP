#include "../include/PizzaFactory.h"

unique_ptr<IPizza> PizzaFactory::createPizza( PizzaType _pizzatype )
    {
        /* 
        Declare a std::unique_ptr that will manage an IPizza object. 
        Initially, it is empty (does not manage any object).
        */
        unique_ptr<IPizza> pizza;

        switch (_pizzatype)
        {
        case HamMushroom:
            /*
            - Create a new HamAndMushroomPizza object and transfers ownership 
            of the object to the std::unique_ptr pizza. 
            - The std::make_unique function ensures that the object is created 
            and managed by the std::unique_ptr in a single, exception-safe step.
            */
            pizza = make_unique <HamAndMushroomPizza>();
            break;
        
        case Deluxe:
            pizza = make_unique <DeluxePizza>();
            break;
        
        case Seafood:
            pizza = make_unique <SeafoodPizza>();
            break;
        }

        /*
        - Return the std::unique_ptr to the caller. The caller now owns the 
        std::unique_ptr and is responsible for the managed object's lifetime.
        */
        return pizza;
    }