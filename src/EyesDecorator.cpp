#include "../include/EyesDecorator.h"
#include "../include/utils.h"
#include <cmath>
#include <vector>
#include <iostream>


EyesDecorator::EyesDecorator(std::unique_ptr<Bestiole> b) : BestioleDecorator(std::move(b)) 
{
    this->set_delta_y( sample_uniform( bestiole_config.getDELTAy_MIN(), bestiole_config.getDELTAy_MAX() ) );
    this->set_alpha( sample_uniform( bestiole_config.getALPHA_MIN(), bestiole_config.getALPHA_MAX() ) );
    this->set_gamma_y( sample_uniform( bestiole_config.getGAMMAy_MIN(), bestiole_config.getGAMMAy_MAX() ) );

    // cout << "call constructor EyesDecorator" << endl;
};

unique_ptr<Bestiole> EyesDecorator::clone ( void ) const
{
    return make_unique<EyesDecorator>(bestiole->clone()); // Implement clone method
};

EyesDecorator::~EyesDecorator( void ) 
{ 
    // cout << "call destructor EyesDecorator" << endl;
};

void  EyesDecorator::draw_myself( UImg & support ) const 
{
    bestiole->draw_myself( support );

    double eye_angle = M_PI / 12.0;

    double xt = bestiole->get_x() + cos( bestiole->get_orientation() + eye_angle )*bestiole_config.getAFF_SIZE()/0.9;
    double yt = bestiole->get_y() - sin( bestiole->get_orientation() + eye_angle )*bestiole_config.getAFF_SIZE()/0.9; 

    support.draw_circle( xt, yt, bestiole_config.getAFF_SIZE()/8., BROWN );

    xt = bestiole->get_x() + cos( bestiole->get_orientation() - eye_angle )*bestiole_config.getAFF_SIZE()/0.9;
    yt = bestiole->get_y() - sin( bestiole->get_orientation() - eye_angle )*bestiole_config.getAFF_SIZE()/0.9; 

    support.draw_circle( xt, yt, bestiole_config.getAFF_SIZE()/8., BROWN );

    // // Draw vision area
    // double rad1 = ( bestiole->get_orientation() - bestiole->get_alpha()/2.0 );
    // double rad2 = ( bestiole->get_orientation() + bestiole->get_alpha()/2.0 );
    
    // // Calculate points on the circumference
    // const int x1 = bestiole->get_x() +  bestiole->get_delta_y() * cos(rad1);
    // const int y1 = bestiole->get_y() -  bestiole->get_delta_y() * sin(rad1);
    // const int x2 = bestiole->get_x() +  bestiole->get_delta_y() * cos(rad2);
    // const int y2 = bestiole->get_y() -  bestiole->get_delta_y() * sin(rad2);
    
    // // Draw the sector outline
    // support.draw_circle( bestiole->get_x(),  bestiole->get_y(),  bestiole->get_delta_y(), ORANGE, 0.3);
    // support.draw_line( bestiole->get_x(),  bestiole->get_y(), x1, y1, DARK_GREEN, 0.3) ;
    // support.draw_line( bestiole->get_x(),  bestiole->get_y(), x2, y2, DARK_GREEN, 0.3);
};

bool EyesDecorator::detect_bestiole(const Bestiole &other) const 
{
    bool base_detection     = bestiole->detect_bestiole( other );
    bool gamma_vs_psi       = bestiole->get_gamma_y() > other.get_psi();
    bool distance_check     = bestiole->compute_distance( other ) < bestiole->get_delta_y();
    bool angle_check        = abs( bestiole->compute_angle_to( other ) - bestiole->get_orientation() ) < (bestiole->get_alpha() / 2.0);
    
    // Combine all conditions
    return base_detection || (gamma_vs_psi && distance_check && angle_check);
}
