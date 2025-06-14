#ifndef _FINS_DECORATOR_H_
#define _FINS_DECORATOR_H_

#include "../include/BestioleDecorator.h"

class FinsDecorator : public BestioleDecorator 
{
public:
    FinsDecorator(std::unique_ptr<Bestiole> b);
    unique_ptr<Bestiole> clone() const override;
    ~FinsDecorator( void );

    // ---- METHODS --------------------------------------------------------------
    void  draw_myself( UImg & support )                        const override;
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----
};

#endif