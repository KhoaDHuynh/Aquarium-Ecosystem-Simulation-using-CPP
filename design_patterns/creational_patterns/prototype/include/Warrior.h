#ifndef _WARRIOR_H_
#define _WARRIOR_H_

#include "Character.h"
#include <iostream>

// Concrete prototype 1: Warrior
class Warrior : public Character 
{
public:
    Warrior(string n = "Warrior", int h = 100, int ap = 20) 
        : Character(n, h, ap) {}

    Warrior(const Warrior& other) 
        : Character(other.name, other.health, other.attackPower) {}


    Character* clone() const override 
    {
        return new Warrior(*this);      // Deep copy
    }

    void getDescription() const override 
    {
        cout << "Warrior - Name: "  << name 
                    << ", Health: " << health 
                    << ", Attack: " << attackPower << endl;
    }
};

#endif