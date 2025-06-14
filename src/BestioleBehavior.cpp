#include "../include/BestioleBehavior.h"

BehavingContext::BehavingContext(BehavingStrategy* init_strategy) : strategy(init_strategy) {}

void BehavingContext::setStrategy(BehavingStrategy* new_strategy)
{
    strategy = new_strategy;
}

void BehavingContext::executeStrategy(vector<unique_ptr<Bestiole>>& bestiole_list, unique_ptr<Bestiole>& b)
{
    strategy->behave(bestiole_list, b);
}
// ====================================================================================================

void GregariousBehavior::behave(vector<unique_ptr<Bestiole>>& bestiole_list, unique_ptr<Bestiole>& b)
{
    int nb = 0;
    double angle = 0;
    for (const auto& bestiole : bestiole_list)
    {
        if (!(bestiole->is_equal(*b)) && b->detect_bestiole(*bestiole))
        {
            angle += b->compute_angle_to(*bestiole);
            nb++;
        }        
    }
    if (nb!=0) 
    {
        angle /= nb;
        b->set_orientation( angle );
    }
}

// ====================================================================================================
void FearfulBehavior::behave(vector<unique_ptr<Bestiole>>& bestiole_list, unique_ptr<Bestiole>& b)
{
    int nb = 0;
    double angle = 0;
    for (auto& bestiole : bestiole_list)
    {
        if ( !(bestiole->is_equal(*b)) && b->detect_bestiole(*bestiole) )
        {
            angle += b->compute_angle_to( *bestiole );
            nb++;
        }
    };

    if (nb > 5) // Too many nearby Bestioles
    {
        angle /= nb;
        b->set_orientation( M_PI + angle );
        b->set_rho( 2.0 );
    }
    else 
    { 
        b->set_rho( 1.0 ); 
    };
}

// ====================================================================================================
void KamikazeBehavior::behave(vector<unique_ptr<Bestiole>>& bestiole_list, unique_ptr<Bestiole>& b)
{
    double min_distance = numeric_limits<double>::max();
    Bestiole* target = nullptr;

    for (const auto& bestiole : bestiole_list)
    {
        if (!(bestiole->is_equal(*b)) && b->detect_bestiole(*bestiole))
        {
            double distance = b->compute_distance(*bestiole);
            if (distance < min_distance)
            {
                min_distance = distance;
                target = bestiole.get();
            }
        }
    }

    if (target)
    {
        double angle_to_target = b->compute_angle_to(*target);
        b->set_orientation(angle_to_target);
        b->set_rho(1.5); // Increase speed for collision
    }
}

// ====================================================================================================
void ForeseeingBehavior::behave(vector<unique_ptr<Bestiole>>& bestiole_list, unique_ptr<Bestiole>& b)
{
    for (const auto& bestiole : bestiole_list)
    {
        if (!(bestiole->is_equal(*b)) && b->detect_bestiole(*bestiole))
        {
            if (imminent_collision(*bestiole, *b, 1.0)) // Check for imminent collision
            {
                b->set_orientation( b->get_orientation() + M_PI / 2 ); // Adjust trajectory
                b->set_rho(1.5); // Slight speed boost
                return;
            }
        }
    }

    b->set_rho(1.0); // Normal speed
}

bool ForeseeingBehavior::imminent_collision(Bestiole &other, const Bestiole &b, double delay)
{
    double futureX = other.get_x() + cos(other.get_orientation()) * other.get_speed() * delay;
    double futureY = other.get_y() - sin(other.get_orientation()) * other.get_speed() * delay;

    double distance = sqrt(pow(futureX - b.get_x(), 2) + pow(futureY - b.get_y(), 2));
    return distance < b.get_bestiole_config().getAFF_SIZE(); // Collision threshold
}
