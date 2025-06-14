# ifndef _CONFIG_H_
# define _CONFIG_H_

#include <cmath>
#include <map>
#include <string>
#include <iostream>

using namespace std;

class AquariumConfig
{
private:
    // ---- GRAPHIC SETTINGS ------------------------------------------------------------------------------
    int         WIDTH   = 640;          //640
    int         HEIGTH  = 480;          //480 
    int         DELAY   = 30;           //30
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^

    // ---- INIT SETTINGS ---------------------------------------------------------------------------------
    std::map<std::string, double> INIT_POP_DIST;                    // e.g., {"gregarious", 20.0}, {"fearful", 80.0}
    int                           INIT_NUM_BESTIOLES = 20;          //20
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^

public:
    AquariumConfig();
    ~AquariumConfig() = default;                            // Use the compiler-generated default destructor

    // ---- GETTERS ---------------------------------------------------------------------------------------
    int getWIDTH    ()  const { return WIDTH;  }
    int getHEIGTH   ()  const { return HEIGTH; }
    int getDELAY    ()  const { return DELAY;  }

    std::map<std::string, double>   getINIT_POP_DIST        () const { return INIT_POP_DIST;      }
    int                             getINIT_NUM_BESTIOLES   () const { return INIT_NUM_BESTIOLES; }
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^

    // ---- SETTERS ---------------------------------------------------------------------------------------
    void setWIDTH    ( int width  )  { WIDTH  = width;  }  
    void setHEIGTH   ( int heigth )  { HEIGTH = heigth; }
    void setDELAY    ( int delay  )  { DELAY  = delay;  }

    void setINIT_POP_DIST( std::map<std::string, double> pop_dist )     { INIT_POP_DIST = pop_dist; }
    void setINIT_NUM_BESTIOLES( int nb_bestioles )                      { INIT_NUM_BESTIOLES = nb_bestioles; }
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^
};


class BestioleConfig
{
private:
    // ---- BIRTH & DEATH SETTINGS -----------------------------------------------------------------------
    int         AGE_MAX;                // Maximum age of a bestiole
    double      COLLISION_DEATH_RATE;   // Collision death probability
    double      CLONING_RATE;           // Cloning rate
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^

    // ---- EYE SETTINGS ---------------------------------------------------------------------------------
     double      ALPHA_MIN;             // Minimum value of vision angle
     double      ALPHA_MAX;             // Maximum value of vision angle
     double      DELTAy_MIN;            // Minimum value of vision range
     double      DELTAy_MAX;            // Maximum value of vision range
     double      GAMMAy_MIN;            // Minimum value of eye detection capacity
     double      GAMMAy_MAX;            // Maximum value of eye detection capacity
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^

    // ---- EAR SETTINGS ---------------------------------------------------------------------------------
     double      DELTAo_MIN;            // Minimum value of hearing range
     double      DELTAo_MAX;            // Maximum value of hearing range
     double      GAMMAo_MIN;            // Minimum value of ear detection capacity
     double      GAMMAo_MAX;            // Maximum value of ear detection capacity
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^

    // ---- FIN SETTINGS ---------------------------------------------------------------------------------
    double       NUY_MAX;               // Maximum value of speed boost factor
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^

    // ---- SHELL SETTINGS -------------------------------------------------------------------------------
    double       OMEGA_MAX;             // Maximum value of death probability reduction factor
    double       ETA_MAX;               // Maximum value of speed reduction fator
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^

    // ---- CAMOUFLAGE SETTINGS --------------------------------------------------------------------------
    double       PSI_MIN;               // Minimum value of camouflage capacity
    double       PSI_MAX;               // Maximum value of camouflage capacity
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^

    // ---- OTHER SETTINGS -------------------------------------------------------------------------------
    double       AFF_SIZE;              // 8.0 Bestiole's size - 
    double       MAX_VITESSE;           // Maximum velocity of a bestiole
    double       MIN_VITESSE;
    double       LIMITE_VUE;            //    
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^

public:
    BestioleConfig();        
    ~BestioleConfig() = default;                            // Use the compiler-generated default destructor

    // ---- GETTERS ---------------------------------------------------------------------------------------
    int     getAGE_MAX()                const { return AGE_MAX; }
    double  getCOLLISION_DEATH_RATE()   const { return COLLISION_DEATH_RATE; }
    double  getCLONING_RATE()           const { return CLONING_RATE; }

    double  getALPHA_MIN()  const { return ALPHA_MIN; }
    double  getALPHA_MAX()  const { return ALPHA_MAX; }
    double  getDELTAy_MIN() const { return DELTAy_MIN; }
    double  getDELTAy_MAX() const { return DELTAy_MAX; }
    double  getGAMMAy_MIN() const { return GAMMAy_MIN; }
    double  getGAMMAy_MAX() const { return GAMMAy_MAX; }

    double  getDELTAo_MIN() const { return DELTAo_MIN; }
    double  getDELTAo_MAX() const { return DELTAo_MAX; }
    double  getGAMMAo_MIN() const { return GAMMAo_MIN; }
    double  getGAMMAo_MAX() const { return GAMMAo_MAX; }

    double  getNUY_MAX()    const { return NUY_MAX; }

    double  getOMEGA_MAX()  const { return OMEGA_MAX; }
    double  getETA_MAX()    const { return ETA_MAX; }

    double  getPSI_MIN()    const { return PSI_MIN; }
    double  getPSI_MAX()    const { return PSI_MAX; }

    double  getAFF_SIZE()       const { return AFF_SIZE; }
    double  getMAX_VITESSE()    const { return MAX_VITESSE; }
    double  getMIN_VITESSE()    const { return MIN_VITESSE; }
    double  getLIMITE_VUE()     const { return LIMITE_VUE; }
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^

    // ---- SETTERS ---------------------------------------------------------------------------------------
    void setAGE_MAX                 (int age_max) { AGE_MAX = age_max; }
    void setCOLLISION_DEATH_RATE    (double rate) { COLLISION_DEATH_RATE = rate; }
    void setCLONING_RATE            (double rate) { CLONING_RATE = rate; }

    void setALPHA_MIN   (double alpha_min) { ALPHA_MIN = alpha_min; }
    void setALPHA_MAX   (double alpha_max) { ALPHA_MAX = alpha_max; }
    void setDELTAy_MIN  (double delta_min) { DELTAy_MIN = delta_min; }
    void setDELTAy_MAX  (double delta_max) { DELTAy_MAX = delta_max; }
    void setGAMMAy_MIN  (double gamma_min) { GAMMAy_MIN = gamma_min; }
    void setGAMMAy_MAX  (double gamma_max) { GAMMAy_MAX = gamma_max; }

    void setDELTAo_MIN  (double delta_min) { DELTAo_MIN = delta_min; }
    void setDELTAo_MAX  (double delta_max) { DELTAo_MAX = delta_max; }
    void setGAMMAo_MIN  (double gamma_min) { GAMMAo_MIN = gamma_min; }
    void setGAMMAo_MAX  (double gamma_max) { GAMMAo_MAX = gamma_max; }

    void setNUY_MAX     (double nuy_max)    { NUY_MAX = nuy_max; }

    void setOMEGA_MAX   (double omega_max)  { OMEGA_MAX = omega_max; }
    void setETA_MAX     (double eta_max)    { ETA_MAX = eta_max; }

    void setPSI_MIN     (double psi_min) { PSI_MIN = psi_min; }
    void setPSI_MAX     (double psi_max) { PSI_MAX = psi_max; }

    void setAFF_SIZE    (double aff_size)       { AFF_SIZE = aff_size; }
    void setMAX_VITESSE (double max_vitesse)    { MAX_VITESSE = max_vitesse; }
    void setMIN_VITESSE (double min_vitesse)    { MIN_VITESSE = min_vitesse; }
    void setLIMITE_VUE  (double limite_vue)     { LIMITE_VUE = limite_vue; }
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^
};

#endif