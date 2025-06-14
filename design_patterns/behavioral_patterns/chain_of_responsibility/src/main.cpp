#include "../include/UsernamePasswordHandler.h"
#include "../include/OAuthHandler.h"

int main()
{
    AuthenticationHandler* usernamePasswordHandler = new UsernamePasswordHandler();
    AuthenticationHandler* oauthHandler            = new OAuthHandler();

    // Set up the chain
    usernamePasswordHandler->setNextHandler(oauthHandler);

    // Handling authentication for request = "oauth_token"
    usernamePasswordHandler->handleRequest( "oauth_token" );

    // Handling authentication for request = "username_password"
    usernamePasswordHandler->handleRequest( "username_password" );

    // Handling authentication for request = "invalid_method"
    usernamePasswordHandler->handleRequest( "invalid_method" );

    // delete
    delete usernamePasswordHandler;
    delete oauthHandler;

    return 0;
}