#include <iostream>
#include "MapValues.h"
#include "MapIter.h"
#include "Map.h"

int main()
{
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    Map<int, const char*> m1;
    m1[30] = "asd";
    m1[10] = "weqwe";
    m1.Set(30, "Hello world!");
    const char* val; 
    m1.Get(30, val);
    printf("\n%s  %d  %d\n",val,m1.Count(),m.Includes(m1));
    m1.Delete(10);
    m1.Print();
    m1.Clear();
    m1.Print();
    return 0;
}