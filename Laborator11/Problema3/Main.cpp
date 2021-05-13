#include <iostream>
#include "MyVector.h"

int main()
{
    MyVector v;
    v.Add(15);
    v.Add(17);
    v.Add(12);
    v.Add(1);
    v.Add(3);
    v.Add(2);
    v.Delete(1);
    auto f1 = [](int& x) ->bool { x *= 3; return true; };
    auto f2 = [](int& x) ->bool {return (x % 2 == 0); };
    v.Iterate(0, v.GetCount(), f1);
    v.Filter(0, v.GetCount(), f2);
    for (auto it : v)
    {
        std::cout << it << " ";
    }
    std::cout << '\n';
    return 0;
}