#include "../include/Milieu.h"

#include <cstdlib>
#include <ctime>
#include <algorithm>


// ---- STATIC ATTRIBUTES ---------------------------------------------------------------------------
/*
   - Define a static constant array named white that holds three elements of type T. 
   - Each element in the array is cast to type T and initialized to 255.
*/
const T    Milieu::white[]    = { (T)255, (T)255, (T)255 };
// ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^

// ---- CONSTRUCTOR ---------------------------------------------------------------------------------
Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{
   // printf for debugging
   cout << "create Milieu" << endl;

   // Set and link Birth&Death Handlers
   NCDH = new NaturalCauseDeathHandler();
   CCDH = new CollisionCauseDeathHandler();
   CBH  = new CloningBirthHandler();
   NCDH->setNextHandler( CCDH );
   CCDH->setNextHandler( CBH );

   // Set behaviors
   gregarious_behavior  = new GregariousBehavior();
   fearfull_behavior    = new FearfulBehavior();
   kamikaze_behavior    = new KamikazeBehavior();
   foreseeing_behavior  = new ForeseeingBehavior();
   behaving_context     = new BehavingContext( gregarious_behavior );

   // Initialize the random number generator with the current time as the seed.
   std::srand( time(NULL) );
}
// ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^

// ---- DESTRUCTOR -----------------------------------------------------------------------------------
Milieu::~Milieu( void )
{
   // Delete the Natural Cause Death Handler
   delete NCDH;
   delete CCDH;
   delete CBH;

   // Delete
   delete gregarious_behavior;
   delete fearfull_behavior;
   delete kamikaze_behavior;
   delete foreseeing_behavior;
   delete behaving_context;

   // printf for debugging
   cout << "destroy Milieu" << endl;
}
// ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^

// ---- METHODS --------------------------------------------------------------------------------------
void Milieu::step( void )
{
   // Clear the background by filling it with the color white
   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );

   // Birth & Death Handler
   NCDH->handleRequest( listeBestioles );

   // Iterate over all the Bestiole objects in the listeBestioles vector
   for ( auto& bestiole : listeBestioles )
   {
      // A bestiole bahaves
      switch (bestiole->get_behavior_flag())
      {
      case GREGARIOUS:
         behaving_context->setStrategy(gregarious_behavior);
         // behaving_context->executeStrategy(listeBestioles, bestiole);
         break;
      
      case FEARFUL:
         behaving_context->setStrategy(fearfull_behavior);
         // behaving_context->executeStrategy(listeBestioles, bestiole);
         break;
      
      case KAMIKAZE:
         behaving_context->setStrategy(kamikaze_behavior);
         // behaving_context->executeStrategy(listeBestioles, bestiole);
         break;
      
      case FORESEEING:
         behaving_context->setStrategy(foreseeing_behavior);  
         // behaving_context->executeStrategy(listeBestioles, bestiole);
         break;
      
      case MULTI_PERSO:
         if ( sample_binomial(0.01) )
         {
            int flag = sample_randi(1, 4);
            switch ( flag )
            {
            case 1:
               behaving_context->setStrategy(gregarious_behavior);
               break;
            case 2:
               behaving_context->setStrategy(fearfull_behavior);
               break;
            case 3:
               behaving_context->setStrategy(kamikaze_behavior);
               break; 
            case 4:
               behaving_context->setStrategy(foreseeing_behavior);  
               break; 
            default:
               break;
            }
         };
         break;
      default:
         break;
      }
      behaving_context->executeStrategy(listeBestioles, bestiole);
      // A bestiole takes action in this Milieu
      bestiole->action( *this );
      // A bestiole draws itself in the windows
      bestiole->draw_myself( *this );
   }
}
// ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^

// ---- METHODS --------------------------------------------------------------------------------------
void  Milieu::addMember( unique_ptr<Bestiole> b ) 
{ 
   // Initialize Bestiole's coordinates
   b->init_coords(width, height);                // width and heigth indicate max coordinates

   // Add a new Bestiole to the listeBestioles
   listeBestioles.push_back( std::move(b) );    // move the unique pointer into the vector
}
// ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^

// ---- METHODS --------------------------------------------------------------------------------------
int Milieu::nbVoisins( const Bestiole & b )
{
   // Initialize number of neighbors
   int   nb = 0;

   // Iterates over all the Bestiole objects in the listeBestioles vector
   for ( auto& it : listeBestioles )
   {
      // Check if each one is a neighbor (not the same as b and within b's field of view)
      if ( !(b.is_equal(*it)) && b.detect_bestiole(*it) )
      {
         // Increment a counter for each neighbor found
         ++nb;
      }
   }
      
   return nb;
}
// ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^
