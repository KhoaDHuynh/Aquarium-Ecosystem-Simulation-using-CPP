# include "../include/config.h"

// Constructor with default values
AquariumConfig::AquariumConfig()
{
    // Default population distribution 
    INIT_POP_DIST["GREGARIOUS"]         = 20.0;
    INIT_POP_DIST["FEARFUL"]            = 20.0;
    INIT_POP_DIST["KAMIKAZE"]           = 20.0;
    INIT_POP_DIST["FORESEEING"]         = 20.0;
    INIT_POP_DIST["MULTI_PERSO"]        = 20.0;
}

BestioleConfig::BestioleConfig()
{
    // ---- BIRTH & DEATH SETTINGS -----------------------------------------------------------------------
    AGE_MAX                 = 500;      // Maximum age of a bestiole
    COLLISION_DEATH_RATE    = 0.01;     // Collision death probability
    CLONING_RATE            = 0.01;     // Cloning rate
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^

    // ---- EYE SETTINGS ---------------------------------------------------------------------------------
    ALPHA_MIN   = M_PI/6;       // Minimum value of vision angle
    ALPHA_MAX   = 2*M_PI/3.0;   // Maximum value of vision angle
    DELTAy_MIN  = 80.0;         // Minimum value of vision range
    DELTAy_MAX  = 100.0;        // Maximum value of vision range
    GAMMAy_MIN  = 0.0;          // Minimum value of eye detection capacity
    GAMMAy_MAX  = 1.0;          // Maximum value of eye detection capacity
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^

    // ---- EAR SETTINGS ---------------------------------------------------------------------------------
    DELTAo_MIN  = 20.0;         // Minimum value of hearing range
    DELTAo_MAX  = 50.0;        // Maximum value of hearing range
    GAMMAo_MIN  = 0.0;          // Minimum value of ear detection capacity
    GAMMAo_MAX  = 1.0;          // Maximum value of ear detection capacity
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^

    // ---- FIN SETTINGS ---------------------------------------------------------------------------------
    NUY_MAX     = 2.0;          // Maximum value of speed boost factor
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^

    // ---- SHELL SETTINGS -------------------------------------------------------------------------------
    OMEGA_MAX   = 2.0;          // Maximum value of death probability reduction factor
    ETA_MAX     = 2.0;          // Maximum value of speed reduction fator
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^

    // ---- CAMOUFLAGE SETTINGS --------------------------------------------------------------------------
    PSI_MIN     = 0.0;          // Minimum value of camouflage capacity
    PSI_MAX     = 1.0;          // Maximum value of camouflage capacity
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^

    // ---- OTHER SETTINGS -------------------------------------------------------------------------------
    AFF_SIZE      = 10.0;       // 8.0 Bestiole's size - 
    MAX_VITESSE   = 10.0;       // Maximum velocity of a bestiole
    MIN_VITESSE   = 4.0;
    LIMITE_VUE    = 30.0;       //    
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^

}
