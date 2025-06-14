#include "../include/BirthDeathHandler.h"
#include "../include/Bestiole.h"
#include "../include/PlainBestiole.h"
#include "../include/utils.h"
#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

// ============================================================================================
void NaturalCauseDeathHandler::handleRequest(vector<unique_ptr<Bestiole>>& bestiole_list) 
{
    // Remove dead bestioles
    bestiole_list.erase(
        remove_if(bestiole_list.begin(), 
                bestiole_list.end(),
                [](const unique_ptr<Bestiole>& bestiole) 
                { 
                    bestiole->increment_age();
                    return (bestiole->get_age() > bestiole->get_longevity());
                }),
        bestiole_list.end());

    // Pass the request to the next handler if it exists
    if (nextHandler) 
    {
        nextHandler->handleRequest( bestiole_list );
    }
}

// ============================================================================================
void CollisionCauseDeathHandler::handleRequest(vector<unique_ptr<Bestiole>>& bestiole_list) 
{
   // Vector to store indices of bestioles to be removed
   vector<size_t> to_remove;

   // Search for crashed bestioles
   for (size_t i = 0; i < bestiole_list.size(); ++i) 
   {
       for (size_t j = i + 1; j < bestiole_list.size(); ++j) 
       {
            double distance = bestiole_list[i]->compute_distance(*bestiole_list[j]);   

            if (distance <= bestiole_list[i]->get_bestiole_config().getAFF_SIZE())
            {
                // boucing back
                // bestiole_list[i]->set_orientation( bestiole_list[i]->get_orientation() + sample_uniform(-M_PI/2.0, M_PI/2.0) );
                // bestiole_list[j]->set_orientation( bestiole_list[j]->get_orientation() + sample_uniform(-M_PI/2.0, M_PI/2.0) );

                double actual_death_rate_of_i = bestiole_list[i]->get_bestiole_config().getCOLLISION_DEATH_RATE() 
                                                / bestiole_list[i]->get_omega() ;
                double actual_death_rate_of_j = bestiole_list[j]->get_bestiole_config().getCOLLISION_DEATH_RATE() 
                                                / bestiole_list[j]->get_omega() ;

                // Roll a dice to decide if the bestiole is dead
                if ( sample_binomial(actual_death_rate_of_i ) 
                        && ( (bestiole_list[i]->get_speed() * bestiole_list[i]->get_age()) > bestiole_list[i]->get_bestiole_config().getAFF_SIZE() ) )
                {
                    to_remove.push_back(i);
                };
                if ( sample_binomial(actual_death_rate_of_j )
                        && ( (bestiole_list[j]->get_speed() * bestiole_list[j]->get_age()) > bestiole_list[j]->get_bestiole_config().getAFF_SIZE() ) )
                {
                    to_remove.push_back(j);
                };
            }
       }
   }

   // Remove bestioles that died from collisions
   sort(to_remove.begin(), to_remove.end(), greater<size_t>());
   for (size_t index : to_remove) 
   {
       bestiole_list.erase(bestiole_list.begin() + index);
    //    cout << "Bestiole died from collision" << endl;
   }

    // Pass the request to the next handler if it exists
    if (nextHandler) 
    {
        nextHandler->handleRequest( bestiole_list );
    }
}

// ============================================================================================
void CloningBirthHandler::handleRequest(vector<unique_ptr<Bestiole>>& bestiole_list) 
{
    // Clone bestioles
    vector<unique_ptr<Bestiole>> new_bestioles;
    for (auto& bestiole : bestiole_list) 
    {
        if (sample_binomial(bestiole->get_bestiole_config().getCLONING_RATE())) 
            { 
                new_bestioles.push_back(bestiole->clone());
            }
    }

    // Add new bestioles to the list
    for (auto& new_bestiole : new_bestioles) 
    {
        bestiole_list.push_back(move(new_bestiole));
    }
    
    // Pass the request to the next handler if it exists
    if (nextHandler) 
    {
        nextHandler->handleRequest( bestiole_list );
    }
}