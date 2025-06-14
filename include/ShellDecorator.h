#ifndef _SHELL_DECORATOR_H_
#define _SHELL_DECORATOR_H_

#include "../include/BestioleDecorator.h"

class ShellDecorator : public BestioleDecorator 
{
public:
    ShellDecorator(std::unique_ptr<Bestiole> b);
    unique_ptr<Bestiole> clone() const override;
    ~ShellDecorator( void );

    // ---- METHODS --------------------------------------------------------------
    void  draw_myself( UImg & support )                        const override;
    // ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ ----- ^-^ -----
};

#endif