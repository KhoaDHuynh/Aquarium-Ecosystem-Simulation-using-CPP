#ifndef BESTIOLEDECORATOR_H
#define BESTIOLEDECORATOR_H

#include "Bestiole.h"

class BestioleDecorator : public Bestiole 
{
protected:
    Bestiole* bestiole;

public:
    // Constructor
    BestioleDecorator(Bestiole* b);
    // Destructor
    virtual ~BestioleDecorator();

    
    virtual void action(Milieu & monMilieu) override;
    virtual void draw(UImg & support) override;
    virtual bool jeTeVois(const Bestiole & b) const override;
    virtual bool jeTEntends(const Bestiole & b) const override;
    virtual double getCamouflage() const override;

    // We also forward initCoords:
    virtual void initCoords(int xLim, int yLim) override;
    virtual int getX() const { return bestiole->getX(); }
    virtual int getY() const { return bestiole->getY(); }
    virtual double getOrientation() const { return bestiole->getOrientation(); }
    virtual double getVitesse() const override { return bestiole->getVitesse(); }
    virtual void setVitesse(double v) override { bestiole->setVitesse(v); }

};

#endif