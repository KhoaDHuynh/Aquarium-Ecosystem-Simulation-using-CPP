#ifndef _BESTIOLE_FACTORY_H_
#define _BESTIOLE_FACTORY_H_

#include "../include/Bestiole.h"
#include "../include/utils.h"
#include <memory>
using namespace std;

class BestioleFactory
{
public:    

    virtual unique_ptr<Bestiole> createBestiole(BestioleBehaviorType bestiole_behavior) = 0;

    virtual ~BestioleFactory() = default;
};


class BehaviorBasedFactory : public BestioleFactory
{
public:
    unique_ptr<Bestiole> createBestiole(BestioleBehaviorType bestiole_behavior) override;
};
#endif