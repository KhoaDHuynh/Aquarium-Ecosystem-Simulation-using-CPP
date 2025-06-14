#ifndef _CAMOUFLAGE_DECORATOR_H_
#define _CAMOUFLAGE_DECORATOR_H_

#include "../include/BestioleDecorator.h"

class CamouflageDecorator : public BestioleDecorator 
{
public:
    CamouflageDecorator(std::unique_ptr<Bestiole> b);
    unique_ptr<Bestiole> clone() const override;
    ~CamouflageDecorator( void );

    // ---- METHODS --------------------------------------------------------------
    void  draw_myself( UImg & support )                        const override;
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----
};

#endif