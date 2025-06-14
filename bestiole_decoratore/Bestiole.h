#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"

#include <iostream>

#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;


class Milieu;


class Bestiole
{

private :
   static const double     AFF_SIZE;
   static const double     MAX_VITESSE;
   static const double     LIMITE_VUE;

   static int              next;

private :
   int               identite;
   int               x, y;
   double            cumulX, cumulY;
   double            orientation;
   double            vitesse;

   T               * couleur;

private :
   void bouge( int xLim, int yLim );

public :                                           // Forme canonique :
   Bestiole( void );                               // Constructeur par defaut
   Bestiole( const Bestiole & b );                 // Constructeur de copies
   virtual ~Bestiole( void );                      // Destructeur
                                                   // Operateur d'affectation binaire par defaut
   virtual void action( Milieu & monMilieu );
   virtual void draw( UImg & support );

   // detection
   virtual bool jeTeVois( const Bestiole & b ) const;
   virtual bool jeTEntends(const Bestiole & b) const;
   // return camouflage level
   virtual double getCamouflage() const;

   // gettere for position and orientation
   int getX() const { return x; }
   int getY() const { return y; }
   double getOrientation() const { return orientation; }

   // Get and set speed (vitesse)
   virtual double getVitesse() const { return vitesse; }
   virtual void setVitesse(double v) { vitesse = v; }



   virtual void initCoords( int xLim, int yLim );

   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );

};


#endif
