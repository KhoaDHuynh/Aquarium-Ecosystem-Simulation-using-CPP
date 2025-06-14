#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <string>
using namespace std;

// Abstract prototype class
class Character 
{
protected:
    string  name;
    int     health;
    int     attackPower;

public:
    Character(string n, int h, int ap) : name(n), health(h), attackPower(ap) {}
    virtual ~Character() = default;                 // Virtual destructor

    virtual Character*  clone()             const = 0;      // Pure virtual clone method
    virtual void        getDescription()    const = 0;      // Pure virtual display method
};

#endif