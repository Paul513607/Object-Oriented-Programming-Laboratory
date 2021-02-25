#include <iostream>
#include "NumberList.h"

using namespace std;

int main()
{
    NumberList myList;
    myList.Init();
    myList.Add(11);
    myList.Add(42);
    myList.Add(23);
    myList.Add(5);
    myList.Add(100);
    myList.Add(7);
    myList.Print();
    myList.Sort();
    myList.Print();
    return 0;
}
