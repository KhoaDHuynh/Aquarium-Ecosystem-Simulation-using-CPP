#include "../include/FinsDecorator.h"
#include <cmath>
#include <iostream>


FinsDecorator::FinsDecorator(std::unique_ptr<Bestiole> b) : BestioleDecorator(std::move(b)) 
{
    this->set_nu( sample_uniform( 1.0, bestiole_config.getNUY_MAX() ) );
    // cout << "call constructor FinsDecorator" << endl;
};

unique_ptr<Bestiole> FinsDecorator::clone ( void ) const
{
    return make_unique<FinsDecorator>(bestiole->clone()); // Implement clone method
}

FinsDecorator::~FinsDecorator( void ) 
{ 
    // cout << "call destructor FinsDecorator" << endl;
}

void  FinsDecorator::draw_myself( UImg & support ) const 
{
    bestiole->draw_myself( support );

    double tail_angle = M_PI / 6.0;


    support.draw_ellipse( bestiole->get_x(), bestiole->get_y(), 
                            bestiole_config.getAFF_SIZE(), 
                            bestiole_config.getAFF_SIZE()/5., 
                            -( bestiole->get_orientation() + tail_angle )/M_PI*180.0, 
                            bestiole->get_color() );

    support.draw_ellipse( bestiole->get_x(), bestiole->get_y(), 
                            bestiole_config.getAFF_SIZE(), 
                            bestiole_config.getAFF_SIZE()/5., 
                            -( bestiole->get_orientation() - tail_angle )/M_PI*180.0, 
                            bestiole->get_color() );
};

