#include <iostream>
#include <list>
#include "Sort.h"

int main()
{
    std::list<int> ls = {8, 2, 1, 10, 20, 9, 2, 3, 7};
    bubbleSort(ls);
    for (auto it : ls)
        std::cout << it << " ";
    std::cout << '\n';
    return 0;
}