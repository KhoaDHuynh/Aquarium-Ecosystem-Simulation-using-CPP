#ifndef _BIRTH_DEATH_HANDLER_H_
#define _BIRTH_DEATH_HANDLER_H_

#include <string>
using namespace std;

// Handler Interface
class BirthDeathHandler 
{
public:
    virtual void setNextHandler( BirthDeathHandler* handler )   = 0;
    virtual void handleRequest( const string& request )         = 0;

    virtual ~BirthDeathHandler() {};
};

#endif