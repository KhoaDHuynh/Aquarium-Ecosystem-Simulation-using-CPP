#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_

#include <iostream>
#include <vector>
using namespace std;

#include "SortingStrategy.h"

class QuickSort : public SortingStrategy
{
public:
    void sort(vector<int> &arr) override
    {
        cout << "I am implementing Quick Sort Algorithm" << endl;
    }
};

#endif