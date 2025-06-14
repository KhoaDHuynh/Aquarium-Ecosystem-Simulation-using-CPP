#include <iostream>
using namespace std;

#include "../include/config.h"
#include "../include/Aquarium.h"
#include "../include/Milieu.h"
#include "../include/Bestiole.h"
#include "../include/BestioleFactory.h"

#include "../include/PlainBestiole.h"
#include "../include/EarsDecorator.h"
#include "../include/EyesDecorator.h"
#include "../include/FinsDecorator.h"
#include "../include/ShellDecorator.h"
#include "../include/CamouflageDecorator.h"
#include "../include/utils.h"



int main()
{
   // Instantiate the Configuration
   AquariumConfig aquarium_config;
   BestioleConfig bestiole_config;

   // Set the configuration
   map<string, double> init_pop_dist = {
       {"GREGARIOUS"    , 20.0},  
       {"FEARFUL"       , 20.0},     
       {"KAMIKAZE"      , 20.0},    
       {"FORESEEING"    , 20.0},  
       {"MULTI_PERSO"   , 20.0} 
   };

   aquarium_config.setINIT_NUM_BESTIOLES( 50 );
   aquarium_config.setINIT_POP_DIST( init_pop_dist );
   aquarium_config.setDELAY( 60 );

   bestiole_config.setAGE_MAX( 2000 );
   bestiole_config.setCLONING_RATE ( 0.02 );
   bestiole_config.setCOLLISION_DEATH_RATE( 0.5 );
   bestiole_config.setMAX_VITESSE( 5.0 );

   // Save the configuration
   Aquarium::set_aqua_config( aquarium_config );
   Bestiole::set_bestiole_config( bestiole_config );

   // Instantiate an aquarium
   Aquarium ecosysteme;

   // Initialize the simulation
   ecosysteme.init();
   
   // Run simulation
   ecosysteme.run();

   // srand( time(NULL) );

   // unique_ptr<Bestiole> bestiole = make_unique <PlainBestiole>();
   // bestiole = make_unique<EyesDecorator>(move(bestiole));
   // bestiole = make_unique<EarsDecorator>(move(bestiole));
   // bestiole = make_unique<FinsDecorator>(move(bestiole));
   // bestiole = make_unique<ShellDecorator>(move(bestiole));
   // bestiole = make_unique<CamouflageDecorator>(move(bestiole));

   // unique_ptr<Bestiole> copied_bestiole = bestiole->clone();
   // cout << bestiole->get_delta_y() << endl;
//    cout << sample_uniform(-1.0, 1.0) << endl;

   return 0;
}
