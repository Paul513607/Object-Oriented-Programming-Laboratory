#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <cmath>
#include "Number.h"

int maxim(int a,int b)
{
    if (a>b) return a;
    return b;
}

Number::Number()
{
    this->base=0;
    this->value=nullptr;
}

Number::Number(const char * value, int base)
{
    if (base>=2 && base<=16)
    {
        int len=strlen(value);
        char * temp=new char[len+1];
        strncpy(temp,value,len);
        temp[len]='\0';
        this->value=temp;
        this->base=base;
    }
}

Number::Number(int value)
{
    int len;
    if (value==0) len=1;
    else len=log10(value)+1;
    this->value=new char[len+1];
    this->value=itoa(value,this->value,10);
    this->base=10;
}

Number::~Number()
{
    delete[] this->value;
    this->base=0;
}

Number::Number(const Number &n)
{
    int len=strlen(n.value);
    this->value=new char[len+1];
    strcpy(this->value,n.value);
    this->base=n.base;
}

Number::Number(Number &&n)
{
    this->base=n.base;
    int len=strlen(n.value);
    char *temp=new char[len+1];
    strcpy(temp,n.value);
    n.value=nullptr;
    this->value=temp;
    delete[] temp;
}

Number operator + (Number n1, Number n2)
{
    Number n;
    long long nr;
    int newBase=maxim(n1.base,n2.base),len;
    n1.SwitchBase(10);
    n2.SwitchBase(10);
    nr=atoi(n1.value)+atoi(n2.value);
    n.base=newBase;
    len=int(log10(nr))+1;
    n.value=new char[len+1];
    n.value=itoa(nr,n.value,newBase);
    return n;
}

Number operator - (Number n1, Number n2)
{
    Number n;
    long long nr;
    int newBase=maxim(n1.base,n2.base),len;
    n1.SwitchBase(10);
    n2.SwitchBase(10);
    nr=atoi(n1.value)-atoi(n2.value);
    n.base=newBase;
    if (nr>0) len=int(log10(nr))+1;
    else len=1;
    n.value=new char[len+1];
    n.value=itoa(nr,n.value,newBase);
    return n;
}

Number& Number::operator = (int val)
{
    if (this->base==0) this->base=10;
    int len=int(log10(val)/log10(this->base))+1;
    this->value=new char[len+1];
    this->value=itoa(val,this->value,this->base);
    return (*this);
}

Number& Number::operator = (const char * val)
{
    this->base=10;
    this->value=new char(strlen(val)+1);
    strcpy(this->value,val);
    return (*this);
}

Number& Number::operator = (Number n)
{
    this->value=new char[strlen(n.value)+1];
    strcpy(this->value,n.value);
    this->base=n.base;
    return (*this);
}

Number& Number::operator += (Number n)
{
    int Base=maxim(this->base,n.base);
    (*this)=(*this)+n;
    this->base=Base;
    return (*this);
}

Number& Number::operator -= (Number n)
{
    int Base=maxim(this->base,n.base);
    (*this)=(*this)-n;
    this->base=Base;
    return (*this);
}

Number Number::operator ! ()
{
    Number n;
    int i;
    n.value=new char[strlen(this->value)+1];
    strcpy(n.value,this->value);
    n.base=this->base;
    n.SwitchBase(2);
    for (i=0; this->value[i]; ++i)
        n.value[i]='1'-this->value[i]+'0';
    n.SwitchBase(this->base);
    return n;
}

char& Number::operator[](int index)
{
    if (index<strlen(this->value))
    {
        return this->value[index];
    }
}

bool operator > (Number n1,Number n2)
{
    n1.SwitchBase(10);
    n2.SwitchBase(10);
    if (atoi(n1.value)>atoi(n2.value)) return 1;
    return 0;
}

bool operator < (Number n1,Number n2)
{
    n1.SwitchBase(10);
    n2.SwitchBase(10);
    if (atoi(n1.value)<atoi(n2.value)) return 1;
    return 0;
}

bool operator >= (Number n1,Number n2)
{
    n1.SwitchBase(10);
    n2.SwitchBase(10);
    if (atoi(n1.value)>=atoi(n2.value)) return 1;
    return 0;
}

bool operator <= (Number n1,Number n2)
{
    n1.SwitchBase(10);
    n2.SwitchBase(10);
    if (atoi(n1.value)<=atoi(n2.value)) return 1;
    return 0;
}

bool operator == (Number n1,Number n2)
{
    n1.SwitchBase(10);
    n2.SwitchBase(10);
    if (atoi(n1.value)==atoi(n2.value)) return 1;
    return 0;
}

Number& Number::operator -- ()
{
    strcpy(value,value+1);
    return (*this);
}

Number& Number::operator -- (int val)
{
    value[strlen(value)-1]='\0';
    return (*this);
}

int GetInt(char c)
{
    int no;
    if (c>='0' && c<='9') no=int(c-'0');
    else if (c>='A' && c<='F') no=int(c-55);
    else if (c>='a' && c<='f') no=int(c-87);
    return no;
}
char GetChar(int no)
{
    char c;
    if (no>=0 && no<=9) c=char(no+'0');
    else if (no>=10 && no<=15) c=char(no+55);
    return c;
}
int logbase(long long x, int newBase)
{
    return (log(x)/log(newBase));
}
void Number::SwitchBase(int newBase)
{
    if (this->base==newBase) return;
    long long nr=0;
    int i,c,counter,len;
    char digit;
    len=strlen(value);
    for (i=0; value[i]; ++i)
    {
        c=GetInt(value[i]);
        nr=nr+c*pow(base,len-i-1);
    }
    if (newBase>=11) nr++;
    counter=logbase(nr,newBase)+1;
    value[counter]='\0';
    while (nr!=0)
    {
        c=nr%newBase;
        digit=GetChar(c);
        value[--counter]=digit;
        nr/=newBase;
    }
    base=newBase;
}

void Number::Print()
{
    std::cout << value << " base " << base <<'\n';
}

int Number::GetDigitsCount()
{
    return strlen(value);
}

int Number::GetBase()
{
    return base;
}
