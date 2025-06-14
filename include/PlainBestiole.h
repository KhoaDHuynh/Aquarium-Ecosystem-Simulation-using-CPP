#ifndef _PLAIN_BESTIOLE_H_
#define _PLAIN_BESTIOLE_H_

#include <iostream>
#include "../include/Bestiole.h"
using namespace std;

class PlainBestiole : public Bestiole
{
public :
    PlainBestiole( void );
    PlainBestiole( const Bestiole &other ) : Bestiole(other) {};
    ~PlainBestiole( void);

    // ---- METHODS --------------------------------------------------------------
    unique_ptr<Bestiole> clone()                                const override;
    void  draw_myself( UImg & support )                         const override;
    bool  detect_bestiole( const Bestiole &other )              const override;
   // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----
};

#endif
