#ifndef _EYES_DECORATOR_H_
#define _EYES_DECORATOR_H_

#include "../include/BestioleDecorator.h"

class EyesDecorator : public BestioleDecorator 
{
public:
    EyesDecorator(std::unique_ptr<Bestiole> b);
    unique_ptr<Bestiole> clone() const override;
    ~EyesDecorator( void );

    // ---- METHODS --------------------------------------------------------------
    void  draw_myself( UImg & support )              const override;
    bool  detect_bestiole( const Bestiole &other )   const override;
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----
};

#endif