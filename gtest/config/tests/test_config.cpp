#include "../include/config.h"
#include <gtest/gtest.h>
#include <map>
#include <string>

// Test AquariumConfig class
TEST(ConfigTest, AquariumConfig) {
    AquariumConfig aquarium_config;

    // Test default values
    EXPECT_EQ(aquarium_config.getWIDTH()                , 640);         // Assuming default width is 640
    EXPECT_EQ(aquarium_config.getHEIGTH()               , 480);         // Assuming default height is 480
    EXPECT_EQ(aquarium_config.getDELAY()                , 30);          // Assuming default delay is 30
    EXPECT_EQ(aquarium_config.getINIT_NUM_BESTIOLES()   , 10);          // Assuming default number of bestioles is 0

    EXPECT_EQ(aquarium_config.getINIT_POP_DIST()["gregarious"]  , 20.0); 
    EXPECT_EQ(aquarium_config.getINIT_POP_DIST()["fearful"]     , 20.0); 
    EXPECT_EQ(aquarium_config.getINIT_POP_DIST()["kamikaze"]    , 20.0); 
    EXPECT_EQ(aquarium_config.getINIT_POP_DIST()["foreseeing"]  , 20.0); 
    EXPECT_EQ(aquarium_config.getINIT_POP_DIST()["multi_perso"] , 20.0); 

    // Test setters and getters
    aquarium_config.setWIDTH(800);
    aquarium_config.setHEIGTH(600);
    aquarium_config.setDELAY(50);

    EXPECT_EQ(aquarium_config.getWIDTH(), 800);
    EXPECT_EQ(aquarium_config.getHEIGTH(), 600);
    EXPECT_EQ(aquarium_config.getDELAY(), 50);

    std::map<std::string, double> pop_dist = {{"gregarious" ,  5.0}, 
                                            {"fearful"      , 10.0}, 
                                            {"kamikaze"     , 15.0}, 
                                            {"foreseeing"   , 20.0}, 
                                            {"multi_perso"  , 50.0}};

    aquarium_config.setINIT_POP_DIST(pop_dist);
    EXPECT_EQ(aquarium_config.getINIT_POP_DIST(), pop_dist);

    aquarium_config.setINIT_NUM_BESTIOLES(100);
    EXPECT_EQ(aquarium_config.getINIT_NUM_BESTIOLES(), 100);
}

// Test BestioleConfig class
TEST(ConfigTest, BestioleConfig) {
    BestioleConfig bestiole_config;

    // Test default values
    EXPECT_EQ(bestiole_config.getAGE_MAX(), 1000000);
    EXPECT_EQ(bestiole_config.getCOLLISION_DEATH_PROB(), 0.5);
    EXPECT_EQ(bestiole_config.getCLONING_RATE(), 0.01);

    EXPECT_EQ(bestiole_config.getALPHA_MIN(), 0.0);
    EXPECT_EQ(bestiole_config.getALPHA_MAX(), 2 * M_PI);
    EXPECT_EQ(bestiole_config.getDELTAy_MIN(), 0.0);
    EXPECT_EQ(bestiole_config.getDELTAy_MAX(), 10.0);
    EXPECT_EQ(bestiole_config.getGAMMAy_MIN(), 0.0);
    EXPECT_EQ(bestiole_config.getGAMMAy_MAX(), 1.0);

    EXPECT_EQ(bestiole_config.getDELTAo_MIN(), 0.0);
    EXPECT_EQ(bestiole_config.getDELTAo_MAX(), 2.0);
    EXPECT_EQ(bestiole_config.getGAMMAo_MIN(), 0.0);
    EXPECT_EQ(bestiole_config.getGAMMAo_MAX(), 1.0);

    EXPECT_EQ(bestiole_config.getNUY_MAX(), 2.0);

    EXPECT_EQ(bestiole_config.getOMEGA_MAX(), 2.0);
    EXPECT_EQ(bestiole_config.getETA_MAX(), 2.0);

    EXPECT_EQ(bestiole_config.getPSI_MIN(), 0.0);
    EXPECT_EQ(bestiole_config.getPSI_MAX(), 1.0);

    EXPECT_EQ(bestiole_config.getAFF_SIZE(), 8.0);
    EXPECT_EQ(bestiole_config.getMAX_VITESSE(), 10.0);
    EXPECT_EQ(bestiole_config.getLIMITE_VUE(), 30.0);

    // Test setters and getters
    bestiole_config.setAGE_MAX(2000000);
    bestiole_config.setCOLLISION_DEATH_PROB(0.6);
    bestiole_config.setCLONING_RATE(0.02);

    bestiole_config.setALPHA_MIN(0.1);
    bestiole_config.setALPHA_MAX(3 * M_PI);
    bestiole_config.setDELTAy_MIN(1.0);
    bestiole_config.setDELTAy_MAX(20.0);
    bestiole_config.setGAMMAy_MIN(0.1);
    bestiole_config.setGAMMAy_MAX(2.0);

    bestiole_config.setDELTAo_MIN(0.1);
    bestiole_config.setDELTAo_MAX(3.0);
    bestiole_config.setGAMMAo_MIN(0.1);
    bestiole_config.setGAMMAo_MAX(2.0);

    bestiole_config.setNUY_MAX(3.0);

    bestiole_config.setOMEGA_MAX(3.0);
    bestiole_config.setETA_MAX(3.0);

    bestiole_config.setPSI_MIN(0.1);
    bestiole_config.setPSI_MAX(2.0);

    bestiole_config.setAFF_SIZE(10.0);
    bestiole_config.setMAX_VITESSE(15.0);
    bestiole_config.setLIMITE_VUE(40.0);

    EXPECT_EQ(bestiole_config.getAGE_MAX(), 2000000);
    EXPECT_EQ(bestiole_config.getCOLLISION_DEATH_PROB(), 0.6);
    EXPECT_EQ(bestiole_config.getCLONING_RATE(), 0.02);

    EXPECT_EQ(bestiole_config.getALPHA_MIN(), 0.1);
    EXPECT_EQ(bestiole_config.getALPHA_MAX(), 3 * M_PI);
    EXPECT_EQ(bestiole_config.getDELTAy_MIN(), 1.0);
    EXPECT_EQ(bestiole_config.getDELTAy_MAX(), 20.0);
    EXPECT_EQ(bestiole_config.getGAMMAy_MIN(), 0.1);
    EXPECT_EQ(bestiole_config.getGAMMAy_MAX(), 2.0);

    EXPECT_EQ(bestiole_config.getDELTAo_MIN(), 0.1);
    EXPECT_EQ(bestiole_config.getDELTAo_MAX(), 3.0);
    EXPECT_EQ(bestiole_config.getGAMMAo_MIN(), 0.1);
    EXPECT_EQ(bestiole_config.getGAMMAo_MAX(), 2.0);

    EXPECT_EQ(bestiole_config.getNUY_MAX(), 3.0);

    EXPECT_EQ(bestiole_config.getOMEGA_MAX(), 3.0);
    EXPECT_EQ(bestiole_config.getETA_MAX(), 3.0);

    EXPECT_EQ(bestiole_config.getPSI_MIN(), 0.1);
    EXPECT_EQ(bestiole_config.getPSI_MAX(), 2.0);

    EXPECT_EQ(bestiole_config.getAFF_SIZE(), 10.0);
    EXPECT_EQ(bestiole_config.getMAX_VITESSE(), 15.0);
    EXPECT_EQ(bestiole_config.getLIMITE_VUE(), 40.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}