#ifndef _BESTIOLE_DECORATOR_H
#define _BESTIOLE_DECORATOR_H

#include "../include/Bestiole.h"
#include <memory>

using namespace std;

class BestioleDecorator : public Bestiole 
{
protected:
    unique_ptr<Bestiole> bestiole;

public:
    BestioleDecorator(unique_ptr<Bestiole> b): bestiole( std::move(b) ) {};
    virtual ~BestioleDecorator( void ) = default;

    // ---- METHODS --------------------------------------------------------------
    void draw_myself(UImg &support) const override { bestiole->draw_myself(support); }
    bool detect_bestiole(const Bestiole &b) const override { return bestiole->detect_bestiole(b); }

    // ---- METHODS --------------------------------------------------------------
    double    compute_distance(const Bestiole &other )  const override { return bestiole->compute_distance( other ); }
    double    compute_angle_to( const Bestiole &other ) const override { return bestiole->compute_angle_to( other ); };
    void      init_coords(int xLim, int yLim) override { bestiole->init_coords(xLim, yLim); }
    void      bouge( int xLim, int yLim) override { bestiole->bouge(xLim, yLim); }
    void      action( Milieu & monMilieu ) override { bestiole->action( monMilieu ); };
    bool      is_equal( const Bestiole &other)          const override { return bestiole->is_equal( other ); };
    void      set_opposite_orientation( void ) override { bestiole->set_opposite_orientation(); };
    void      set_orientation(const double angle) override { bestiole->set_orientation(angle); }
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----
    
    // ---- GETTERS --------------------------------------------------------------
    BestioleConfig get_bestiole_config(void) const override { return bestiole->get_bestiole_config(); }
    int get_identity(void) const override { return bestiole->get_identity(); }
    int get_longevity(void) const override { return bestiole->get_longevity(); }
    int get_age(void) const override { return bestiole->get_age(); }
    T* get_color(void) const override { return bestiole->get_color(); }
    BestioleBehaviorType get_behavior_flag(void) const override { return bestiole->get_behavior_flag(); }
    int get_x(void) const override { return bestiole->get_x(); }
    int get_y(void) const override { return bestiole->get_y(); }
    double get_cumulX(void) const override { return bestiole->get_cumulX(); }
    double get_cumulY(void) const override { return bestiole->get_cumulY(); }
    double get_orientation(void) const override { return bestiole->get_orientation(); }
    double get_speed(void) const override { return bestiole->get_speed(); }
    double get_alpha(void) const override { return bestiole->get_alpha(); }
    double get_rho(void) const override { return bestiole->get_rho(); }
    double get_delta_y(void) const override { return bestiole->get_delta_y(); }
    double get_gamma_y(void) const override { return bestiole->get_gamma_y(); }
    double get_delta_o(void) const override { return bestiole->get_delta_o(); }
    double get_gamma_o(void) const override { return bestiole->get_gamma_o(); }
    double get_nu(void) const override { return bestiole->get_nu(); }
    double get_omega(void) const override { return bestiole->get_omega(); }
    double get_eta(void) const override { return bestiole->get_eta(); }
    double get_psi(void) const override { return bestiole->get_psi(); }

    // ---- SETTERS --------------------------------------------------------------
    void set_identity(const int id) override { bestiole->set_identity(id); }
    void set_longevity(const int l) override { bestiole->set_longevity(l); }
    void set_age(const int a) override { bestiole->set_age(a); }
    void set_color(const T *c) override { bestiole->set_color(c); }
    void set_behavior_flag(const BestioleBehaviorType flag) override { bestiole->set_behavior_flag(flag); }
    void set_x(const int new_x) override { bestiole->set_x(new_x); }
    void set_y(const int new_y) override { bestiole->set_y(new_y); }
    void set_cumulX(const double new_cumulX) override { bestiole->set_cumulX(new_cumulX); }
    void set_cumulY(const double new_cumulY) override { bestiole->set_cumulY(new_cumulY); }
    void set_speed(const double new_speed) override { bestiole->set_speed(new_speed); }
    void set_rho(const double new_rho) override { bestiole->set_rho(new_rho); }
    void set_alpha(const double new_alpha) override { bestiole->set_alpha(new_alpha); }
    void set_delta_y(const double new_delta_y) override { bestiole->set_delta_y(new_delta_y); }
    void set_gamma_y(const double new_gamma_y) override { bestiole->set_gamma_y(new_gamma_y); }
    void set_delta_o(const double new_delta_o) override { bestiole->set_delta_o(new_delta_o); }
    void set_gamma_o(const double new_gamma_o) override { bestiole->set_gamma_o(new_gamma_o); }
    void set_nu(const double new_nu) override { bestiole->set_nu(new_nu); }
    void set_omega(const double new_omega) override { bestiole->set_omega(new_omega); }
    void set_eta(const double new_eta) override { bestiole->set_eta(new_eta); }
    void set_psi(const double new_psi) override { bestiole->set_psi(new_psi); }
    void increment_age(void) override { bestiole->increment_age(); }
};

#endif