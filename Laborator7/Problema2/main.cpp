#include <iostream>
#include <stdio.h>
#include <string.h>
#include <initializer_list>
#include "Vector.h"

int main()
{
    Vector<int> a;
    Vector<int> b({6,4,2,1,8,10,3,2,2,100});
    b.push(11);
    a.push(100); a.push(10); a.push(50); a.push(-1);
    a.insert(40,2);
    a.insert(40,8);
    a.print();
    a.pop();
    a.sort(nullptr);
    a.print();
    a.remove(3);
    a.Set(8000,2);
    a.print();
    std::cout << a.top() << " " << a.Count() << '\n' << a.Get(2) << '\n';
    b.print();
    b.sort(nullptr);
    b.print();
    std::cout << b.firstIndexOf(2,nullptr);
    return 0;
}
