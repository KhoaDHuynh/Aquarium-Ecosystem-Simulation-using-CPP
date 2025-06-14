#include "IPizza.h"

class DeluxePizza : public IPizza
{
private:
    double price = 12.0;
public:
    double getPrice() const override {return price;}
};
