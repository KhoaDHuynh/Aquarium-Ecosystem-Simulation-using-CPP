#ifndef _COFEE_H
#define _COFEE_H

class Coffee {
protected:
    double price;
public:
    double up_price() const;
    virtual void get_description() const = 0;
    void get_price() const;
    virtual ~Coffee(); 
};

class PlainCoffee : public Coffee {
public:
    PlainCoffee();
    void get_description() const override;
};

class CoffeeDecorator : public Coffee {
protected:
    Coffee* coffee;
public:
    CoffeeDecorator(Coffee* coffee, double extraCost);
    virtual ~CoffeeDecorator();
};

class Milk : public CoffeeDecorator {
public:
    Milk(Coffee* coffee);
    void get_description() const override;
};

class Sugar: public CoffeeDecorator {
public:
    Sugar(Coffee* coffee);
    void get_description() const override;
};


#endif