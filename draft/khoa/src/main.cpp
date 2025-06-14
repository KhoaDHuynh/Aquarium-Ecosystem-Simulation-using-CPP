#include <iostream>
#include <memory>
#include <vector>
#include <algorithm> // Include this header for remove_if
#include "../include/Coffee.h"
#include "../include/PlainCoffee.h"
#include "../include/MilkDecorator.h"
#include "../include/SugarDecorator.h"

using namespace std;

int main() {
    // Create a vector to store coffee objects
    vector<unique_ptr<Coffee>> coffee_list;

    // Create a plain coffee
    unique_ptr<Coffee> plain_one = make_unique<PlainCoffee>();
    cout << "Order: "        << plain_one->getDescription() 
              << "\t\t, Cost: $"  << plain_one->getCost()
              << endl;
    cout << "ID: " << plain_one->id << endl;
    cout << "Counter: " << plain_one->counter << endl;

    // Create a milk coffee
    unique_ptr<Coffee> milk_one = make_unique<MilkDecorator>(make_unique<PlainCoffee>());
    cout << "Order: "      << milk_one->getDescription() 
              << "\t, Cost: $"  << milk_one->getCost()
              << endl;
    cout << "ID: " << milk_one->id << endl;
    cout << "Counter: " << milk_one->counter << endl;

    // Create a sugar coffee
    unique_ptr<Coffee> sugar_one = make_unique<SugarDecorator>(make_unique<PlainCoffee>());
    cout << "Order: "      << sugar_one->getDescription() 
              << "\t, Cost: $"  << sugar_one->getCost()
              << endl;
    cout << "ID: " << sugar_one->id << endl;
    cout << "Counter: " << sugar_one->counter << endl;

    // Create a milk + sugar coffee
    unique_ptr<Coffee> mixed_one = make_unique<SugarDecorator>(make_unique<MilkDecorator>(make_unique<PlainCoffee>()));
    cout << "Order: "      << mixed_one->getDescription() 
              << "\t, Cost: $"  << mixed_one->getCost()
              << endl;
    cout << "ID: " << mixed_one->id << endl;
    cout << "Counter: " << mixed_one->counter << endl;

    // Copy a decorated coffee
    unique_ptr<Coffee> copied_coffee = milk_one->clone();
    cout << "\nCopied Order: " << copied_coffee->getDescription() 
                << "\t, Cost: $"  << copied_coffee->getCost()
                << endl;
                
    coffee_list.push_back(move(plain_one));
    coffee_list.push_back(move(milk_one));
    coffee_list.push_back(move(sugar_one));
    coffee_list.push_back(move(mixed_one));

    // Step 1: Create a lambda function to check if the cost exceeds 12
    auto is_cost_exceeding_12 = [](const unique_ptr<Coffee>& coffee) 
    {
        return coffee->getCost() > 12;
    };

    // Step 2: Use remove_if to get the iterator to the new end of the range
    auto new_end = remove_if(coffee_list.begin(), coffee_list.end(), is_cost_exceeding_12);

    // Step 3: Use erase to remove the elements from the vector
    coffee_list.erase(new_end, coffee_list.end());

    // // Loop over the vector and remove any coffee object whose cost exceeds 12
    // coffee_list.erase(
    //     remove_if(coffee_list.begin(), 
    //                 coffee_list.end(),
    //                 [](const unique_ptr<Coffee>& coffee) {
    //                     return coffee->getCost() > 12;
    //                 }),
    //                 coffee_list.end());
    
    
    // Print remaining coffee orders
    for (const auto& coffee : coffee_list) {
        cout << "\nRemaining Order: " << coffee->getDescription() 
                  << "\t, Cost: $" << coffee->getCost() << endl;
    }

    return 0;
}