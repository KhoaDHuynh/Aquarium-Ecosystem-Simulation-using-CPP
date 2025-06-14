#include "../include/BestioleFactory.h"
#include "../include/PlainBestiole.h"
#include "../include/EarsDecorator.h"
#include "../include/EyesDecorator.h"
#include "../include/FinsDecorator.h"
#include "../include/ShellDecorator.h"
#include "../include/CamouflageDecorator.h"


unique_ptr<Bestiole> BehaviorBasedFactory::createBestiole( BestioleBehaviorType bestiole_behavior )
{
    /* 
    Declare a std::unique_ptr that will manage an Bestiole object. 
    Initially, it is empty (does not manage any object).
    */
    unique_ptr<Bestiole> bestiole;

    switch( bestiole_behavior )
    {
    case GREGARIOUS:
        /*
        - Create a new Bestiole object and transfers ownership 
        of the object to the std::unique_ptr bestiole. 
        - The std::make_unique function ensures that the object is created 
        and managed by the std::unique_ptr in a single, exception-safe step.
        */
        bestiole = make_unique <PlainBestiole>();
        bestiole->set_behavior_flag( GREGARIOUS );
        bestiole->set_color( RED );
        // std::cout << "create a GREGARIOUS Bestiole" << std::endl;

        break;
    
    case FEARFUL:
        bestiole = make_unique <PlainBestiole>();
        bestiole->set_behavior_flag( FEARFUL );
        bestiole->set_color( GREY );
        // std::cout << "create a FEARFUL Bestiole" << std::endl;

        break;
    
    case KAMIKAZE:
        bestiole = make_unique <PlainBestiole>();
        bestiole->set_behavior_flag( KAMIKAZE );
        bestiole->set_color( BLACK );
        // std::cout << "create a KAMIKAZE Bestiole" << std::endl;

        break;
    
    case FORESEEING:
        bestiole = make_unique <PlainBestiole>();
        bestiole->set_behavior_flag( FORESEEING );
        bestiole->set_color( YELLOW );
        // std::cout << "create a FORESEEING Bestiole" << std::endl;

        break;

    case MULTI_PERSO:
        bestiole = make_unique <PlainBestiole>();
        bestiole->set_behavior_flag( MULTI_PERSO );
        bestiole->set_color( BLUE );
        // std::cout << "create a MULTI_PERSO Bestiole" << std::endl;

        break;
    }

    /*
    - Return the std::unique_ptr to the caller. The caller now owns the 
    std::unique_ptr and is responsible for the managed object's lifetime.
    */
    if (sample_binomial( 0.5 )) { bestiole = make_unique<EyesDecorator>(move(bestiole)); }
    if (sample_binomial( 1.0 )) { bestiole = make_unique<EarsDecorator>(move(bestiole)); }
    if (sample_binomial( 0.5 )) { bestiole = make_unique<FinsDecorator>(move(bestiole)); }
    if (sample_binomial( 0.5 )) { bestiole = make_unique<ShellDecorator>(move(bestiole)); }
    if (sample_binomial( 0.5 )) { bestiole = make_unique<CamouflageDecorator>(move(bestiole)); }

    return bestiole;
}