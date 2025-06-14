#ifndef _USERNAMPASSWORDHANDLER_H_
#define _USERNAMPASSWORDHANDLER_H_

#include <iostream>
#include <string>
using namespace std;

#include "BirthDeathHandler.h"

// Handler Interface
class CollisionCauseDeathHandler : public BirthDeathHandler 
{
private:
    BirthDeathHandler* nextHandler;

public:
    void setNextHandler(BirthDeathHandler* handler) override
    {
        nextHandler = handler;
    }

    void handleRequest(const std::string& request) override
    {
        std::cout << "Collision Cause Death Handler." << std::endl;

        std::cout << "Passing request to next handler." << std::endl;
        nextHandler->handleRequest(request);
    }  

};

#endif