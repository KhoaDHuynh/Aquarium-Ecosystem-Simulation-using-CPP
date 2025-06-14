#ifndef _NATURAL_CAUSE_DEATH_HANDLER_H_
#define _NATURAL_CAUSE_DEATH_HANDLER_H_

#include <iostream>
#include <string>
using namespace std;

#include "BirthDeathHandler.h"

class NaturalCauseDeathHandler : public BirthDeathHandler {
private:
    BirthDeathHandler* nextHandler;

public:
    void setNextHandler(BirthDeathHandler* handler) override 
    {
        nextHandler = handler;
    }

    void handleRequest(const std::string& request) override 
    {
        std::cout << "Natural Cause Death Handler." << std::endl;

        std::cout << "Passing request to next handler." << std::endl;
        nextHandler->handleRequest(request);
    }
};
    
#endif