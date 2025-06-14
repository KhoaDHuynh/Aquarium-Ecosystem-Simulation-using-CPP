#include "../include/utils.h"
#include "../include/UImg.h"
#include "../include/Bestiole.h"

bool sample_binomial( double p )
{
    return ( static_cast<double>( rand() )/RAND_MAX ) < p;
}

double sample_uniform( double min, double max ) 
{
    return min + static_cast<double>(rand()) / RAND_MAX * (max - min);
};

int sample_randi(int min, int max)
{
    return min + rand() % (max - min + 1);
}

// void estimateTrajectory(Bestiole &other, double &futureX, double &futureY, double delay)
// {
//     futureX = other.get_x() + cos(other.get_orientation()) * other.get_speed() * delay;
//     futureY = other.get_y() + sin(other.get_orientation()) * other.get_speed() * delay;
// }
