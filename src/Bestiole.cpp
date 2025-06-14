#include "../include/Bestiole.h"
#include "../include/Milieu.h"

#include <cstdlib>
#include <cmath>

// ---- PRIVATE STATIC ATTRIBUTES of BESTIOLE CLASS --------------------------------------------------
int               Bestiole::counter         = 0   ;               // Counter: number of created instances
BestioleConfig    Bestiole::bestiole_config = BestioleConfig();   // Bestiole configuration
// ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^


// ---- COPY CONSTRUCTOR -----------------------------------------------------------------------------
Bestiole::Bestiole( const Bestiole &other )
{
   // Increment counter, assign counter value to identite
   identity = ++counter;

   // Reset bestiole's age and speed-up factor
   age = 0;
   rho = 1.0;

   // Set attributes default values
   behavior_flag    = other.get_behavior_flag();
   alpha            = other.get_alpha();
   delta_y          = other.get_delta_y();
   gamma_y          = other.get_gamma_y();
   delta_o          = other.get_delta_o();
   gamma_o          = other.get_gamma_o();
   nu               = other.get_nu();
   omega            = other.get_omega();
   eta              = other.get_eta();
   psi              = other.get_psi();

   // printf for debugging
//    cout << "create a PlainBestiole (" << identity << ") by copy" << endl;

   // Set bestiole's initial position and fractional movement variables
   x = other.get_x();
   y = other.get_y();
   cumulX = cumulY = 0.;

   // Set bestiole's longevity
   longevity = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*bestiole_config.getAGE_MAX() );

   // Assign the bestiole a random orientation and speed
   orientation = sample_uniform( 0.0, 2*M_PI );        
   speed       = sample_uniform( bestiole_config.getMIN_VITESSE(), bestiole_config.getMAX_VITESSE() );    // Speed

   // Assign the bestiole a random color
   color = make_unique<T[]>(3);
   memcpy( color.get(), other.get_color(), 3*sizeof(T) );
};
// ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^

// ---- METHODS --------------------------------------------------------------------------------------
double Bestiole::compute_distance(const Bestiole &other ) const 
{
    double dx = x - other.get_x();
    double dy = y - other.get_y();
    return sqrt(dx * dx + dy * dy);
};

double Bestiole::compute_angle_to( const Bestiole &other ) const
{
    double dx = x - other.get_x();
    double dy = y - other.get_y();

    double angle = M_PI - atan2(dy, dx);
    if (angle < 0) { angle += 2 * M_PI; };

    return angle;
};

void Bestiole::init_coords( int xLim, int yLim )
{
   // Set the x and y coordinates to random values between 0 and xLim - 1 and between 0 and yLim - 1
   x = rand() % xLim;
   y = rand() % yLim;
};

void Bestiole::bouge( int xLim, int yLim )
{
    double v = rho*speed*nu/eta;
    // Next state indicating variables
    double         nx, ny;                                // New x, new y
    double         dx = cos( orientation )*v;             // dx
    double         dy = -sin( orientation )*v;            // dy
    int            cx, cy;                                // Integer part of cumulX and CumulY

    // Remove integer part of cumulX and cumulY
    cx = static_cast<int>( cumulX ); cumulX -= cx;
    cy = static_cast<int>( cumulY ); cumulY -= cy;

    // Calculate new positions
    nx = x + dx + cx;
    ny = y + dy + cy;

    // HIT THE WALL: check x-axis boundary conditions
    if ( (nx < 0) || (nx > xLim - 1) ) 
    {
        // if hit the wall, then change direction and reset cumulX
        orientation = fmod(M_PI - orientation, 2*M_PI);
        if (orientation < 0) { orientation += 2 * M_PI; };
        cumulX      = 0.;
    }
    else 
    {
        // else, step forwards in x direction and update cumulX
        x = static_cast<int>( nx );
        cumulX += nx - x;
    }

    // HIT THE FLOOR/CEIL: check y-axis boundary conditions
    if ( (ny < 0) || (ny > yLim - 1) ) 
    {
        // if hit the floor/ceil, then change direction and reset cumulY
        orientation = fmod(2*M_PI - orientation, 2*M_PI);
        if (orientation < 0) { orientation += 2 * M_PI; };
        cumulY = 0.;
    }
    else 
    {
        // else, step forwards in y direction and update cumulY
        y = static_cast<int>( ny );
        cumulY += ny - y;
    }
};

void Bestiole::action( Milieu & monMilieu )
{
   // Bestiole take a step
   this->bouge( monMilieu.getWidth(), monMilieu.getHeight() );
};

bool Bestiole::is_equal( const Bestiole &other) const
{
    // Two bestioles are identical if their identities are equal
   return ( this->get_identity() == other.get_identity() );
};

void Bestiole::set_opposite_orientation( void )
{
    orientation = fmod(orientation + M_PI, 2*M_PI);
    if (orientation < 0) { orientation += 2 * M_PI; };
};

void Bestiole::set_orientation( const double angle )
{
    orientation = fmod(angle, 2*M_PI);
    if (orientation < 0) { orientation += 2 * M_PI; };
}
// ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^