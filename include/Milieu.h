#ifndef _MILIEU_H_
#define _MILIEU_H_

#include "../include/UImg.h"
#include "../include/BirthDeathHandler.h"
#include "../include/BestioleBehavior.h"
#include "../include/Bestiole.h"

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Milieu : public UImg
{
private :
   // ---- ATTRIBUTES -----------------------------------------------------------
   /* Background color of Milieu
      - The static keyword means that the white array is shared among all instances 
      of the Milieu class. There is only one copy of the white array, regardless of 
      how many Milieu objects are created.
   */
   static const T                      white[];             // Background color of Milieu
   int                                 width, height;       // Width and Heigth of window
   std::vector<unique_ptr<Bestiole>>   listeBestioles;      // Store unique pointers to Bestiole objects

   BirthDeathHandler*                  NCDH;                // Natural Cause Death Handler
   BirthDeathHandler*                  CCDH;                // Collision Cause Death Handler
   BirthDeathHandler*                  CBH;                 // Cloning Birth Handler

   BehavingStrategy*                   gregarious_behavior;
   BehavingStrategy*                   fearfull_behavior;
   BehavingStrategy*                   kamikaze_behavior;
   BehavingStrategy*                   foreseeing_behavior;
   BehavingContext*                    behaving_context;
   // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----

public :
   // ---- CONSTRUCTOR ----------------------------------------------------------
   /* Constructor of the Milieu class
      - Initialize the base class UImg with the specified width and height, 
      sets the width and height member variables, prints a debug message, and 
      seeds the random number generator with the current time. 
   */
   Milieu( int _width, int _height );
   // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----

   // ---- DISTRUCTOR -----------------------------------------------------------
   ~Milieu( void );
   // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----

   // ---- METHODS --------------------------------------------------------------
   int   getWidth ( void ) const { return width;  };     // get window's width
   int   getHeight( void ) const { return height; };     // get window's heigth

   /* step method of the Milieu class 
      - Perform a single step in the simulation. 
      - It first clears the background by filling it with the color white. 
      - Then, it iterates over all the Bestiole objects in the listeBestioles vector, 
      calling their action and draw methods to update their state and render them 
      on the Milieu.
   */
   void  step( void );

   /* addMember method of the Milieu class
      - Add a new Bestiole to the listeBestioles vector and initializes its coordinates. 
      - It takes a unique pointer to a Bestiole, calls the initCoords method on the newly 
      Bestiole to set its initial position within the dimensions of the Milieu, then moves 
      the unique pointer into the vector, 
   */
   void  addMember( unique_ptr<Bestiole> b );
   
   /* nbVoisins method of the Milieu class 
      - Calculate the number of neighboring Bestiole objects that a given Bestiole 
      object b can see. 
      - It iterates over all the Bestiole objects in the listeBestioles vector, 
      checks if each one is a neighbor (not the same as b and within b's field of view), 
      and increments a counter for each neighbor found. The method then returns 
      the total count of neighbors.
   */
   int   nbVoisins( const Bestiole & b );
   // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----
};
#endif
