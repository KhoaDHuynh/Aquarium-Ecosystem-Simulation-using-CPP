#include "../include/CharacterFactory.h"
#include "../include/Warrior.h"
#include "../include/Mage.h"
#include <iostream>

int main() 
{
    CharacterFactory factory;

    // Register prototypes
    factory.registerPrototype("Warrior", new Warrior());
    factory.registerPrototype("Mage", new Mage());

    // Create characters
    Character* warrior = factory.createCharacter("Warrior");
    Character* mage = factory.createCharacter("Mage");

    // Display characters
    if (warrior) 
    {
        warrior->getDescription();
        delete warrior;
    }

    if (mage) 
    {
        mage->getDescription();
        delete mage;
    }

    return 0;
}