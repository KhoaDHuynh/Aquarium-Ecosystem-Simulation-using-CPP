#ifndef _AUTHENTICATIONHANDLER_H_
#define _AUTHENTICATIONHANDLER_H_

#include <string>
using namespace std;

// Handler Interface
class AuthenticationHandler 
{
public:
    virtual void setNextHandler(AuthenticationHandler* handler) = 0;
    virtual void handleRequest(const string& request)           = 0;

    virtual ~AuthenticationHandler() {};
};

#endif