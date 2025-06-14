#ifndef _MAGE_H_
#define _MAGE_H_

#include "Character.h"
#include <iostream>

// Concrete prototype 2: Mage
class Mage : public Character 
{
public:
    Mage(string n = "Mage", int h = 80, int ap = 30) 
        : Character(n, h, ap) {}

    Mage(const Mage& other)
        : Character(other.name, other.health, other.attackPower) {}

    Character* clone() const override 
    {
        return new Mage(*this);  // Deep copy
    }

    void getDescription() const override 
    {
        cout << "Mage - Name: " << name 
                << ", Health: " << health 
                << ", Attack: " << attackPower << endl;
    }
};

#endif