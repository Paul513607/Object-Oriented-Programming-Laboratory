#include <iostream>
#include <cstring>
#include <stdarg.h>
#include "Math.h"

int Math::Add(int x, int y)
{
    return x+y;
}

int Math::Add(int x, int y, int z)
{
    return x+y+z;
}

int Math::Add(double x, double y)
{
    return x+y;
}

int Math::Add(double x, double y, double z)
{
    return x+y+z;
}

int Math::Mul(int x, int y)
{
    return x*y;
}

int Math::Mul(int x, int y, int z)
{
    return x*y*z;
}

int Math::Mul(double x, double y)
{
    return x*y;
}

int Math::Mul(double x, double y, double z)
{
    return x*y*z;
}

int Math::Add(int count, ...)
{
    va_list l;
    va_start(l,count);
    int sum=0,i;
    for (i=0; i<count; ++i)
    {
        sum+=va_arg(l,int);
    }
    va_end(l);
    return sum;
}

char* Math::Add(const char *p, const char *q)
{
    if(p==nullptr || q==nullptr) return nullptr;
    static char *r=(char*)malloc(strlen(p)+strlen(q)+1);
    int nr1,nr2;
    strcpy(r,p);
    strcat(r,q);
    return r;
}
