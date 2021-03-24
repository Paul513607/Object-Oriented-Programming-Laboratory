#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stdarg.h>
#include <cstring>
#include <initializer_list>
#include "Sort.h"

Sort::Sort(int n,int min,int max)
{
    srand(time(0));
    this->n=n;
    for (int i=0; i<n; ++i)
        v[i]=rand()%(max-min+1)+min;
}

//Sort::Sort(std::<initializer_list> l){}

Sort::Sort(int n,int v[])
{
    this->n=n;
    for (int i=0; i<n; ++i)
        this->v[i]=v[i];
}

Sort::Sort(int n, ...)
{
    va_list l;
    this->n=n;
    va_start(l,n);
    for (int i=0; i<n; ++i)
        v[i]=va_arg(l,int);
    va_end(l);
}

int convert_to_int(char *s)
{
    int i,nr=0,ogl=0;
    for (i=0; s[i]; ++i)
        if (s[i]>='0' && s[i]<='9')
            nr=nr*10+int(s[i]-'0');
    return nr;
}

Sort::Sort(const char *s)
{
    char *cuv,*s1;
    n=0;
    strcpy(s1,s);
    cuv=strtok(s1,",");
    while (cuv)
    {
        v[n++]=convert_to_int(cuv);
        cuv=strtok(NULL,",");
    }
}

bool compare(int x,int y,bool ascendent)
{
    if (ascendent==true)
    {
        if (x>=y) return true;
        return false;
    }
    else
    {
        if (x<=y) return true;
        return false;
    }
}

void inter(int &x,int &y)
{
    int aux=x;
    x=y;
    y=aux;
}

void Sort::InsertSort(bool ascendent)
{
    int i,j,temp;
    for (i=1; i<n; ++i)
    {
        temp=v[i];
        j=i-1;
        while (j>=0 && compare(v[j],temp,ascendent))
        {
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=temp;
    }
}

int partitions(int v[],int l,int h,bool ascendent)
{
    int temp=v[l],i=l+1,j=h;
    while (i<=j)
    {
        while (!compare(v[i],temp,ascendent))
            i++;
        while (compare(v[j],temp,ascendent))
            j--;
        if (i<j)
        {
            inter(v[i],v[j]);
            i++;
            j--;
        }
    }
    inter(v[j],v[l]);
    return j;
}

void Sort::QuickSort(bool ascendent)
{
    int l=0,h=n-1,st[n+1],top=-1,p;
    st[++top]=l;
    st[++top]=h;
    while (top>=0)
    {
        h=st[top--];
        l=st[top--];
        p=partitions(v,l,h,ascendent);
        if (p-1>l)
        {
            st[++top]=l;
            st[++top]=p-1;
        }
        if (p+1<h)
        {
            st[++top]=p+1;
            st[++top]=h;
        }
    }
}

void Sort::BubbleSort(bool ascendent)
{
    int m=n,i,ok;
    do
    {
        ok=0;
        for (i=0; i<m-1; ++i)
            if (compare(v[i],v[i+1],ascendent))
            {
                inter(v[i],v[i+1]);
                ok=1;
            }
        m--;
    }
    while (ok==1);
}

void Sort::Print()
{
    int i;
    for (i=0; i<n; ++i)
        std::cout << v[i] << " ";
    std::cout << '\n';
}

int Sort::GetElementsCount()
{
    return n;
}

int Sort::GetElementFromIndex(int i)
{
    return v[i];
}
