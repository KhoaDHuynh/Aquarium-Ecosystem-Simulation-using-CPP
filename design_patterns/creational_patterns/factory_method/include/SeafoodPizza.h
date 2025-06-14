#include "IPizza.h"

class SeafoodPizza : public IPizza
{
private:
    double price = 14.0;
public:
    double getPrice() const override {return price;}
};

