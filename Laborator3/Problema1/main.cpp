#include <iostream>
#include <cstring>
#include <stdarg.h>
#include "Math.h"

int main()
{
    Math m;
    char *s;
    std::cout << Math::Add(10,20) << '\n' << Math::Add(10,5,100) << '\n' << Math::Add(10.5,20.3) << '\n' << Math::Add(10.3,20.3,5.4) << '\n';
    std::cout << Math::Mul(10,20) << '\n' << Math::Mul(10,5,100) << '\n' << Math::Mul(10.5,20.3) << '\n' << Math::Mul(10.3,20.3,5.4) << '\n';
    std::cout << Math::Add(5,1,2,3,4,5) << '\n';
    s=Math::Add("123","27");
    std::cout << s;
    return 0;
}
