#ifndef _BESTIOLE_H_
#define _BESTIOLE_H_

#include <iostream>
#include <memory>
using namespace std;

#include "../include/UImg.h"
#include "../include/config.h"
#include "../include/utils.h"

class Milieu;

class Bestiole
{
protected :
   static BestioleConfig   bestiole_config;  // Bestiole configuration
   static int              counter;          // Counter: number of created instances
   // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----

protected :
   // ---- ATTRIBUTES -----------------------------------------------------------
      // Identity attributes
   int                  identity;               // Bestiole's identity number
   int                  longevity;              // Bestiole's longevity
   int                  age;                    // Bestiole's age
   unique_ptr<T[]>      color;                  // Bestiole's color
  
   BestioleBehaviorType behavior_flag;          // Bestiole's behavior flag
      // Dynamic motion attributes
   int                  x, y;                   // Bestiole's position
   double               cumulX, cumulY;         // Fractional cumulative movement since a bestiole can take a non-integer step
   double               orientation;            // [0, 2pi] moving direction (angle)
   double               speed;                  // Speed
   double               rho;                    // Speed-up factor
      // Sensor attributes
   double               alpha;                  // Vision angle
   double               delta_y;                // Vision distance
   double               gamma_y;                // Vision detection capacity
   double               delta_o;                // Olfaction distance
   double               gamma_o;                // Olfaction detection capacity
      // Accesory attributes
   double               nu;                     // Velocity boost factor
   double               omega;                  // Death probability reduction factor
   double               eta;                    // Velocity reduction factor
   double               psi;                    // Camouflage capacity
   // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----

public :                                           // Forme canonique :
   Bestiole( void ) = default;                              
   virtual ~Bestiole( void ) = default;            // Destructor
                                                   // Operateur d'affectation binaire par defaut

   Bestiole( const Bestiole &other);
   // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----

   // ---- METHODS --------------------------------------------------------------
   virtual unique_ptr<Bestiole> clone( void )               const = 0;
   virtual void  draw_myself( UImg & support )              const = 0;
   virtual bool  detect_bestiole( const Bestiole & b )      const = 0;
   // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----

   // ---- METHODS --------------------------------------------------------------
   virtual double    compute_distance(const Bestiole &other )  const;
   virtual double    compute_angle_to( const Bestiole &other ) const;
   virtual void      init_coords ( int xLim, int yLim );
   virtual void      bouge( int xLim, int yLim);
   virtual void      action( Milieu & monMilieu );
   virtual bool      is_equal( const Bestiole &other)          const;
   virtual void      set_opposite_orientation( void );
   virtual void      set_orientation(const double angle);


   // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----

   // ---- GETTERS & SETTERS ----------------------------------------------------
   virtual BestioleConfig       get_bestiole_config( void )   const { return bestiole_config; }

   virtual int                  get_identity( void )          const { return identity; }
   virtual int                  get_longevity( void )         const { return longevity; }
   virtual int                  get_age( void )               const { return age; }
   virtual T*                   get_color( void )             const { return color.get(); }
   virtual BestioleBehaviorType get_behavior_flag( void )     const { return behavior_flag; }

   virtual int                  get_x( void )                 const { return x; }
   virtual int                  get_y( void )                 const { return y; }
   virtual double               get_cumulX( void )            const { return cumulX; }
   virtual double               get_cumulY( void )            const { return cumulY; }
   virtual double               get_orientation( void )       const { return orientation; }
   virtual double               get_speed( void )             const { return speed; }
   virtual double               get_rho ( void )              const { return rho; }

   virtual double               get_alpha( void )             const { return alpha; }
   virtual double               get_delta_y( void )           const { return delta_y; }
   virtual double               get_gamma_y( void )           const { return gamma_y; }
   virtual double               get_delta_o( void )           const { return delta_o; }
   virtual double               get_gamma_o( void )           const { return gamma_o; }

   virtual double               get_nu( void )                const { return nu; }
   virtual double               get_omega( void )             const { return omega; }
   virtual double               get_eta( void )               const { return eta; }
   virtual double               get_psi( void )               const { return psi; }
   
   // Setters
   static void set_bestiole_config(const BestioleConfig &config) { bestiole_config = config; }

   virtual void set_identity(const int id)                     { identity = id; }
   virtual void set_longevity(const int l)                     { longevity = l; }
   virtual void set_age(const int a)                           { age = a; }
   virtual void set_color(const T *c)                          { memcpy(color.get(), c, 3 * sizeof(T)); }
   virtual void set_behavior_flag(const BestioleBehaviorType flag) { behavior_flag = flag; }

   virtual void set_x(const int new_x)                         { x = new_x; }
   virtual void set_y(const int new_y)                         { y = new_y; }
   virtual void set_cumulX(const double new_cumulX)            { cumulX = new_cumulX; }
   virtual void set_cumulY(const double new_cumulY)            { cumulY = new_cumulY; }
   virtual void set_speed(const double new_speed)              { speed = new_speed; }
   virtual void set_rho( const double new_rho)                 { rho = new_rho; }

   virtual void set_alpha(const double new_alpha)              { alpha = new_alpha; }
   virtual void set_delta_y(const double new_delta_y)          { delta_y = new_delta_y; }
   virtual void set_gamma_y(const double new_gamma_y)          { gamma_y = new_gamma_y; }
   virtual void set_delta_o(const double new_delta_o)          { delta_o = new_delta_o; }
   virtual void set_gamma_o(const double new_gamma_o)          { gamma_o = new_gamma_o; }

   virtual void set_nu(const double new_nu)                    { nu = new_nu; }
   virtual void set_omega(const double new_omega)              { omega = new_omega; }
   virtual void set_eta(const double new_eta)                  { eta = new_eta; }
   virtual void set_psi(const double new_psi)                  { psi = new_psi; }

   virtual void increment_age(void)                            { age++; }
   // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----
};

#endif
