#ifndef _UTILS_H_
#define _UTILS_H_

#include "UImg.h"
#include <cstdlib>
#include <map>

using namespace std;

// Fundamental colors
const T GREEN[3]    = {0, 255, 0};
const T GREY[3]     = {128, 128, 128};
const T BLACK[3]    = {0, 0, 0};
const T YELLOW[3]   = {255, 255, 0};
const T BLUE[3]     = {0, 0, 255};
const T WHITE[3]    = {255, 255, 255};
const T RED[3]      = {255, 0, 0};

// Additional colors
const T ORANGE[3]     = {255, 165, 0};
const T PURPLE[3]     = {128, 0, 128};
const T CYAN[3]       = {0, 255, 255};
const T MAGENTA[3]    = {255, 0, 255};
const T BROWN[3]      = {165, 42, 42};
const T PINK[3]       = {255, 192, 203};
const T LIGHT_BLUE[3] = {173, 216, 230};
const T DARK_GREEN[3] = {0, 100, 0};
const T LIGHT_GREY[3] = {211, 211, 211};
const T DARK_GREY[3]  = {169, 169, 169};
const T LIGHT_GREEN[3] = {144, 238, 144}; // Light green color

enum BestioleBehaviorType {GREGARIOUS, FEARFUL, KAMIKAZE, FORESEEING, MULTI_PERSO};

bool sample_binomial( double p );

double sample_uniform(double min, double max);

int sample_randi( int min, int max );

// void estimateTrajectory(Bestiole &other, double &futureX, double &futureY, double delay = 1.0);
#endif