#include "../include/Aquarium.h"
#include "../include/Milieu.h"
#include "../include/BestioleFactory.h"

AquariumConfig    Aquarium::aqua_config = AquariumConfig();  // Bestiole configuration

// ---- CONSTRUCTOR ---------------------------------------------------------------------------------
Aquarium::Aquarium( void ) : CImgDisplay()
{
   // Get screen width and heigth
   int   screenWidth  = screen_width() ;    //or 1280
   int   screenHeight = screen_height();    //or 1024

   // printf for debugging
   cout << "create Aquarium" << endl;

   // Instantiate an environment and assign it to the display
   flotte = new Milieu( aqua_config.getWIDTH(), aqua_config.getHEIGTH() );
   assign( *flotte, "Ecosystem Simulation" );

   // Instantiate a behavior factory
   behavior_based_factory = new BehaviorBasedFactory();

   // Center the window on the screen 
   move( static_cast<int>((screenWidth-aqua_config.getWIDTH())/2), static_cast<int>((screenHeight-aqua_config.getHEIGTH())/2) );
}
// ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^

// ---- DESTRUCTOR -----------------------------------------------------------------------------------
Aquarium::~Aquarium( void )
{
   // Delete the environment on the HEAP
   delete flotte;

   // Delete the behavior factory
   delete behavior_based_factory;

   // printf for debugging 
   cout << "destroy Aquarium" << endl;
}
// ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^

// ---- METHODS --------------------------------------------------------------------------------------
void Aquarium::run( void )
{
   // printf for debugging
   cout << "running Aquarium" << endl;

   // Loop if not closed
   while ( ! is_closed() )
   {
      // cout << "iteration de la simulation" << endl;

      // Capture key press, if ESC then close
      if ( is_key() ) {
         cout << "Vous avez presse la touche " << static_cast<unsigned char>( key() );
         cout << " (" << key() << ")" << endl;
         if ( is_keyESC() ) close();
      }

      // simulation++, then display new state
      flotte->step();
      display( *flotte );

      // wait
      wait( aqua_config.getDELAY() );
   }
}
// ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^

// ---- METHODS --------------------------------------------------------------------------------------
void Aquarium::init( void )
{
   // printf for debugging
   cout << "init Aquarium" << endl;

   // Add GREGARIOUS bestioles in that environment
   int nb_gregarious = static_cast<int>( static_cast<double>( aqua_config.getINIT_NUM_BESTIOLES() )
                                          *aqua_config.getINIT_POP_DIST()["GREGARIOUS"]
                                          /100.0 );
   for ( int i = 0; i < nb_gregarious; i++ )
   {
      flotte->addMember( behavior_based_factory->createBestiole( GREGARIOUS ) );
   }

   // Add FEARFUL bestioles in that environment
   int nb_fearful = static_cast<int>( static_cast<double>( aqua_config.getINIT_NUM_BESTIOLES() )
                                       *aqua_config.getINIT_POP_DIST()["FEARFUL"]
                                       /100.0 );

   for ( int i = 0; i < nb_fearful; i++ )
   {
      flotte->addMember( behavior_based_factory->createBestiole( FEARFUL ) );
   }

   // Add KAMIKAZE bestioles in that environment
   int nb_kamikaze = static_cast<int>( static_cast<double>( aqua_config.getINIT_NUM_BESTIOLES() )
                                       *aqua_config.getINIT_POP_DIST()["KAMIKAZE"]
                                       /100.0 );

   for ( int i = 0; i < nb_kamikaze; i++ )
   {
      flotte->addMember( behavior_based_factory->createBestiole( KAMIKAZE ) );
   }

   // Add FORESEEING bestioles in that environment
   int nb_foresighted = static_cast<int>( static_cast<double>( aqua_config.getINIT_NUM_BESTIOLES() )
                                          *aqua_config.getINIT_POP_DIST()["FORESEEING"]
                                          /100.0 );

   for ( int i = 0; i < nb_foresighted; i++ )
   {
      flotte->addMember( behavior_based_factory->createBestiole( FORESEEING ) );
   }

   // Add MULTI_PERSO bestioles in that environment
   int nb_multi_perso = static_cast<int>( static_cast<double>( aqua_config.getINIT_NUM_BESTIOLES() )
                                          *aqua_config.getINIT_POP_DIST()["MULTI_PERSO"]
                                          /100.0 );

   for ( int i = 0; i < nb_multi_perso; i++ )
   {
      flotte->addMember( behavior_based_factory->createBestiole( MULTI_PERSO ) );
   }


}

// ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^