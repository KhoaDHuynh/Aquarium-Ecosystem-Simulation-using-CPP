#include "IPizza.h"

class HamAndMushroomPizza : public IPizza
{
private:
    double price = 10.0;
public:
    double getPrice() const override {return price;}
};
