#ifndef _SORTINGCONTEXT_H_
#define _SORTINGCONTEXT_H_

#include <vector>
using namespace std;

#include "SortingStrategy.h"

class SortingContext
{
private:
    SortingStrategy* strategy;
public:
    void setStrategy(SortingStrategy* _strategy)
    {
        this->strategy = _strategy;
    }

    void executeStrategy(vector<int> &arr)
    {
        strategy->sort(arr);
    }
};

#endif