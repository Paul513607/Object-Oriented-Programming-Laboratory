#include "NumberList.h"
#include <iostream>

using namespace std;

void NumberList::Init()
{
    count=0;
}

bool NumberList::Add(int x)
{
    if (count>=10) return false;
    numbers[count]=x;
    count++;
    return true;
}

void inter(int &x,int &y)
{
    int aux=x;
    x=y;
    y=aux;
}

void NumberList::Sort()
{
    int i,ok,m=count;
    do
    {
        ok=0;
        for (i=0; i<m-1; ++i)
            if (numbers[i]>numbers[i+1])
            {
                inter(numbers[i],numbers[i+1]);
                ok=1;
            }
        m--;
    }
    while (ok==1);
}

void NumberList::Print()
{
    int i;
    for (i=0; i<count; ++i)
        cout << numbers[i] << " ";
    cout << '\n';
}
