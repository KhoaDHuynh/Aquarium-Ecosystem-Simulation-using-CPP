#include "../include/ShellDecorator.h"
#include <cmath>
#include <iostream>


ShellDecorator::ShellDecorator(std::unique_ptr<Bestiole> b) : BestioleDecorator(std::move(b)) 
{
    this->set_omega( sample_uniform( 1, bestiole_config.getOMEGA_MAX() ) );
    this->set_eta( sample_uniform( 1, bestiole_config.getETA_MAX() ) );

    // cout << "call constructor ShellDecorator" << endl;
};

unique_ptr<Bestiole> ShellDecorator::clone ( void ) const
{
    return make_unique<ShellDecorator>(bestiole->clone()); // Implement clone method
}

ShellDecorator::~ShellDecorator( void ) 
{ 
    // cout << "call destructor ShellDecorator" << endl;
}

void  ShellDecorator::draw_myself( UImg & support ) const 
{
    bestiole->draw_myself( support );



    support.draw_ellipse( bestiole->get_x(), bestiole->get_y(), 
                            bestiole_config.getAFF_SIZE()/2, 
                            bestiole_config.getAFF_SIZE()/10., 
                            -bestiole->get_orientation()/M_PI*180.0, 
                            DARK_GREY );

};