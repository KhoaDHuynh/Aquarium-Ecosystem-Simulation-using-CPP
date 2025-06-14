#ifndef _AQUARIUM_H_
#define _AQUARIUM_H_

#include <iostream>
#include "../include/CImg.h"
#include "../include/BestioleFactory.h"
#include "../include/config.h"

using namespace std;
using namespace cimg_library;

class Milieu;

class Aquarium : public CImgDisplay
{
private :
   // ---- ATTRIBUTES -----------------------------------------------------------
   Milieu *                flotte;
   BestioleFactory *       behavior_based_factory;
   static AquariumConfig   aqua_config;
   // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----

public :
   // ---- CONSTRUCTOR ----------------------------------------------------------   
   /* CONSTRUCTOR
      - The constructor of the Aquarium class initializes the display, sets the delay, 
      creates a Milieu object, assigns it to the display, and centers the window 
      on the screen. 
      - It also prints a debug message to indicate that the constructor 
      is being called.
   */
   Aquarium( void);
   // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----

   // ---- DESTRUCTOR -----------------------------------------------------------
   /* DISTRUCTOR
      - Delete the Milieu on the HEAP.
      - Print a debug message to indicate that the destructor is being called.
   */
   ~Aquarium( void );
   // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----

   // ---- METHODS --------------------------------------------------------------
   /*
      - Get pointer of Milieu
   */
   Milieu & getMilieu( void ) { return *flotte; }
   
   /* INITIALIZATION METHOD
      - The init method initializes the simulation by creating the bestioles population
      and adding them to the Milieu.
   */
  void init( void );
  
   /* RUN SIMULATION
      - The run method is the main loop of the Aquarium simulation. It continuously 
      updates the simulation and renders the new state to the display until the 
      display window is closed. 
      - It also handles key presses, allowing the user to close the window by pressing 
      the ESC key. The method uses a delay to control the speed of the simulation.
   */
   void run( void );
   // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----

   static void set_aqua_config( const AquariumConfig & config ) { aqua_config = config; }
};
#endif
