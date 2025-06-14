#ifndef _BUBBLESORT_H_
#define _BUBBLESORT_H_

#include <iostream>
#include <vector>
using namespace std;

#include "SortingStrategy.h"

class BubbleSort : public SortingStrategy
{
public:
    void sort(vector<int> &arr) override
    {
        cout << "I am implementing Bubble Sort Algorithm" << endl;
    }
};

#endif