#ifndef _OAUTHHANDLER_H_
#define _OAUTHHANDLER_H_

#include <iostream>
#include <string>
using namespace std;

#include "AuthenticationHandler.h"

class OAuthHandler : public AuthenticationHandler {
private:
    AuthenticationHandler* nextHandler;

public:
    void setNextHandler(AuthenticationHandler* handler) override 
    {
        nextHandler = handler;
    }

    void handleRequest(const std::string& request) override 
    {
        if (request == "oauth_token") 
        {
            std::cout << "Authenticated using OAuth token." << std::endl;
        } 
        else if (nextHandler != nullptr) 
        {
            nextHandler->handleRequest(request);
        } 
        else 
        {
            std::cout << "Invalid authentication method." << std::endl;
        }
    }
};
    
#endif