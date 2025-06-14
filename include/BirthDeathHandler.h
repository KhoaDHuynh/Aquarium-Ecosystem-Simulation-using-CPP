#ifndef _BIRTH_DEATH_HANDLER_H_
#define _BIRTH_DEATH_HANDLER_H_

#include "../include/Bestiole.h"
#include <memory>
#include <vector>
using namespace std;

class BirthDeathHandler
{
public:    
    virtual void setNextHandler( BirthDeathHandler* handler ) = 0;

    virtual void handleRequest( vector<unique_ptr<Bestiole>>& bestiole_list ) = 0;

    virtual ~BirthDeathHandler() = default;
};


class NaturalCauseDeathHandler : public BirthDeathHandler 
{
private:
    BirthDeathHandler* nextHandler = nullptr;

public:
    void setNextHandler(BirthDeathHandler* handler) override { nextHandler = handler; };

    void handleRequest(vector<unique_ptr<Bestiole>>& bestiole_list) override;
};

class CollisionCauseDeathHandler : public BirthDeathHandler 
{
private:
    BirthDeathHandler* nextHandler  = nullptr;

public:

    void setNextHandler(BirthDeathHandler* handler) override { nextHandler = handler; };

    void handleRequest(vector<unique_ptr<Bestiole>>& bestiole_list) override;

};


class CloningBirthHandler : public BirthDeathHandler 
{
private:
    BirthDeathHandler* nextHandler  = nullptr;

public:

    void setNextHandler(BirthDeathHandler* handler) override { nextHandler = handler; };

    void handleRequest(vector<unique_ptr<Bestiole>>& bestiole_list) override;
};
#endif