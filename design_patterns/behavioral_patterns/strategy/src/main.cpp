#include <iostream>
#include <vector>
using namespace std;

#include "../include/SortingContext.h"
#include "../include/BubbleSort.h"
#include "../include/QuickSort.h"

int main()
{
    vector<int> data = {5, 2, 7, 1, 9};

    SortingContext  context;
    BubbleSort      bubble;
    QuickSort       quick;

    context.setStrategy(&bubble);
    context.executeStrategy(data);

    context.setStrategy(&quick);
    context.executeStrategy(data);
    
    return 0;
}