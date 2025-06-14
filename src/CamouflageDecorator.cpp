#include "../include/CamouflageDecorator.h"
#include <cmath>
#include <iostream>


CamouflageDecorator::CamouflageDecorator(std::unique_ptr<Bestiole> b) : BestioleDecorator(std::move(b)) 
{
    this->set_psi( sample_uniform( bestiole_config.getPSI_MIN(), bestiole_config.getPSI_MAX() ) );
    
    // cout << "call constructor CamouflageDecorator" << endl;
};

unique_ptr<Bestiole> CamouflageDecorator::clone ( void ) const
{
    return make_unique<CamouflageDecorator>(bestiole->clone()); // Implement clone method
}

CamouflageDecorator::~CamouflageDecorator( void ) 
{ 
    // cout << "call destructor CamouflageDecorator" << endl;
}

void  CamouflageDecorator::draw_myself( UImg & support ) const 
{
    bestiole->draw_myself( support );

    // Get circle center (a little bit farther from bestiole's postion)
   double   xt = bestiole->get_x() + cos( bestiole->get_orientation() )*bestiole_config.getAFF_SIZE()/2.1;
   double   yt = bestiole->get_y() - sin( bestiole->get_orientation() )*bestiole_config.getAFF_SIZE()/2.1;

   // Draw a circle at bestiole's position
   support.draw_circle( xt, yt, bestiole_config.getAFF_SIZE()/4., WHITE );
};
