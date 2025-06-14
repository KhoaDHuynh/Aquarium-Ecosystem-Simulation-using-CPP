#include "../include/EarsDecorator.h"
#include "../include/utils.h"

#include <cmath>
#include <iostream>


EarsDecorator::EarsDecorator(std::unique_ptr<Bestiole> b) : BestioleDecorator(std::move(b)) 
{
    this->set_delta_o(  sample_uniform( bestiole_config.getDELTAo_MIN(), bestiole_config.getDELTAo_MAX() ) );
    this->set_gamma_o( sample_uniform( bestiole_config.getGAMMAo_MIN(), bestiole_config.getGAMMAo_MAX() ) );
    // cout << "call constructor EarsDecorator" << endl;
};

unique_ptr<Bestiole> EarsDecorator::clone ( void ) const
{
    return make_unique<EarsDecorator>(bestiole->clone()); // Implement clone method
};

EarsDecorator::~EarsDecorator( void ) 
{ 
    // cout << "call destructor EarsDecorator" << endl;
};

void EarsDecorator::draw_myself( UImg &support ) const
{
    // First, draw the base Bestiole
    bestiole->draw_myself(support);

    // Get circle center (a little bit farther from bestiole's postion)
    double   xt = bestiole->get_x() + cos( bestiole->get_orientation() )*bestiole_config.getAFF_SIZE()/2.1;
    double   yt = bestiole->get_y() - sin( bestiole->get_orientation() )*bestiole_config.getAFF_SIZE()/2.1;

    double ear_angle = M_PI / 1.8;

    double x_ear_center = xt + cos( bestiole->get_orientation() + ear_angle )*bestiole_config.getAFF_SIZE()/1.9;
    double y_ear_center = yt - sin( bestiole->get_orientation() + ear_angle )*bestiole_config.getAFF_SIZE()/1.9; 

    support.draw_circle( x_ear_center, y_ear_center, bestiole_config.getAFF_SIZE()/5., PURPLE );

    x_ear_center = xt + cos( bestiole->get_orientation() - ear_angle )*bestiole_config.getAFF_SIZE()/1.9;
    y_ear_center = yt - sin( bestiole->get_orientation() - ear_angle )*bestiole_config.getAFF_SIZE()/1.9; 

    support.draw_circle( x_ear_center, y_ear_center, bestiole_config.getAFF_SIZE()/5., PURPLE );

    // Draw hearable area
    // support.draw_circle(bestiole->get_x(), bestiole->get_y(), bestiole->get_delta_o(), LIGHT_BLUE, 0.3); // Semi-transparent circle
}

bool EarsDecorator::detect_bestiole( const Bestiole & b ) const 
{
    bool i_hear_you = ( bestiole->compute_distance(b) < bestiole->get_delta_o() ) && ( bestiole->get_gamma_o() > b.get_psi() );

    return bestiole->detect_bestiole(b) || i_hear_you;
};
