#include <iostream>
#include <initializer_list>
#include "Sort.h"

int main()
{
    bool ascendent=true;
    int v[100]={1,2,3,4,10,2};
    Sort d1(10,50,150),d2({1,2,3,4,2,5}),d3(6,v),d4(5,9,0,14,20,18),d5("10,40,100,5,70");
    d1.Print();
    d2.Print();
    d3.Print();
    d4.Print();
    d5.Print();
    std::cout << '\n';
    d1.InsertSort(true);
    d1.Print();
    d3.BubbleSort(false);
    d3.Print();
    d5.QuickSort(true);
    d5.Print();
    std::cout << '\n';
    std::cout << d1.GetElementsCount() << " " << d4.GetElementFromIndex(3);
    return 0;
}
