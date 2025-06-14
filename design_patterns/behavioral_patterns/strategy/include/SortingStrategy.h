#ifndef _SORTINGSTRATEGY_H_
#define _SORTINGSTRATEGY_H_

#include <vector>
using namespace std;

class SortingStrategy
{
public:
    virtual void sort(vector<int> &arr) = 0;
};

#endif