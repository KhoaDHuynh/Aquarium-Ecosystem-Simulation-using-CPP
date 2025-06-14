#ifndef _PIZZA_H_
#define _PIZZA_H_

#include <string>
#include <iostream>

// Product class
class Pizza 
{
private:
    std::string dough;
    std::string sauce;
    std::string topping;

public:
    void setDough(const std::string& dough)
    {
        this->dough = dough;
    }

    void setSauce(const std::string& sauce)
    {
        this->sauce = sauce;
    }

    void setTopping(const std::string& topping)
    {
        this->topping = topping;
    }

    void displayPizza() const
    {
        std::cout << "Pizza with Dough: " << dough
                    << ", Sauce: "        << sauce
                    << ", Topping: "      << topping 
                    << std::endl;
    }
};
    

#endif