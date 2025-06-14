#ifndef _USERNAMPASSWORDHANDLER_H_
#define _USERNAMPASSWORDHANDLER_H_

#include <iostream>
#include <string>
using namespace std;

#include "AuthenticationHandler.h"

// Handler Interface
class UsernamePasswordHandler : public AuthenticationHandler 
{
private:
    AuthenticationHandler* nextHandler;

public:
    void setNextHandler(AuthenticationHandler* handler) override
    {
        nextHandler = handler;
    }

    void handleRequest(const std::string& request) override
    {
        if (request == "username_password") 
        {
            std::cout << "Authenticated using username and "
                         "password."
                      << std::endl;
        }
        else if (nextHandler != nullptr) 
        {
            nextHandler->handleRequest(request);
        }
        else 
        {
            std::cout << "Invalid authentication method."
                      << std::endl;
        }
    }  

};

#endif