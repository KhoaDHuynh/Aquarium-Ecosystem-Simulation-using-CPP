#ifndef _EARS_DECORATOR_H_
#define _EARS_DECORATOR_H_

#include "../include/BestioleDecorator.h"

class EarsDecorator : public BestioleDecorator 
{
public:
    EarsDecorator(std::unique_ptr<Bestiole> b);
    unique_ptr<Bestiole> clone() const override;
    ~EarsDecorator( void );

    // ---- METHODS --------------------------------------------------------------
    void  draw_myself( UImg & support )              const override;
    bool  detect_bestiole( const Bestiole & b )      const override;
   // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----
};

#endif