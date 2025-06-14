#include "../include/PlainBestiole.h"
#include <cstdlib>
#include <cmath>

PlainBestiole::PlainBestiole( void )
{
   // Set attributes default values
   identity = ++counter;
   age      = 0.0;
   rho      = 1.0;
   alpha    = 0.0;
   delta_y  = 0.0;
   gamma_y  = 0.0;
   delta_o  = 0.0;
   gamma_o  = 0.0;
   nu       = 1.0;
   omega    = 1.0;
   eta      = 1.0;
   psi      = 0.0;

   // printf for debugging
   // cout << "create a PlainBestiole (" << identity << ") by defaut" << endl;

   // Set bestiole's longevity
   longevity = sample_randi( 0, bestiole_config.getAGE_MAX() );
   
   // Set bestiole's initial position and fractional movement variables
   x = y = 0;
   cumulX = cumulY = 0.0;

   // Assign the bestiole a random orientation and speed
   orientation = sample_uniform( 0.0, 2*M_PI );        
   speed       = sample_uniform( bestiole_config.getMIN_VITESSE(), bestiole_config.getMAX_VITESSE() );    // Speed

   // Assign the bestiole a random color
   color = make_unique<T[]>(3);
   color[ 0 ]  = sample_randi(0, 230);
   color[ 1 ]  = sample_randi(0, 230);
   color[ 2 ]  = sample_randi(0, 230);
};

// ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^

PlainBestiole::~PlainBestiole( void )
{
   // printf for debugging
   // cout << "destroy a PlainBestiole" << endl;
};

unique_ptr<Bestiole> PlainBestiole::clone() const 
{
    return make_unique<PlainBestiole>(*this); // Implement clone method
};

void PlainBestiole::draw_myself( UImg & support ) const
{
   // Get circle center (a little bit farther from bestiole's postion)
   double   xt = x + cos( orientation )*bestiole_config.getAFF_SIZE()/2.1;
   double   yt = y - sin( orientation )*bestiole_config.getAFF_SIZE()/2.1;

   // Draw an ellipse at circle center
   support.draw_ellipse( x, y, bestiole_config.getAFF_SIZE(), bestiole_config.getAFF_SIZE()/5., -orientation/M_PI*180., color.get() );
   // Draw a circle at bestiole's position
   support.draw_circle( xt, yt, bestiole_config.getAFF_SIZE()/2., color.get() );
};

bool PlainBestiole::detect_bestiole( const Bestiole &other ) const 
{
   return false;
};
