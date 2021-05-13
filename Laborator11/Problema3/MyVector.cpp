#include <iostream>
#include "MyVector.h"

MyVector::MyVector()
{
    max_size = 10;
    count = 0;
    v = new int[max_size];
}

void MyVector::ReallocMemory()
{
    int i;
    int* v_copy;
    v_copy = new  int[max_size];
    for (i = 0; i < count; ++i)
        v_copy[i] = this->v[i];
    max_size *= 2;
    delete[] this->v;
    this->v = new int[max_size];
    for (i = 0; i < count; ++i)
        this->v[i] = v_copy[i];
    delete[] v_copy;
}

bool MyVector::Add(const int& value)
{
    if (count + 1 > 1000) return false;
    if (count + 1 > max_size) ReallocMemory();
    v[count] = value;
    count++;
    return true;
}

bool MyVector::Delete(int index)
{
    if (index < 0 || index >= count || count == 0) return false;
    for (int i = index + 1; i < count; ++i)
        v[i - 1] = v[i];
    count--;
}

void MyVector::Iterate(int i1, int i2, bool (*f)(int& val))
{
    for (int i = i1; i < i2; ++i)
    {
        f(v[i]);
    }
}

void MyVector::Filter(int i1, int i2, bool (*f)(int& val))
{
    i2--;
    for (int i = i1; i < i2; ++i)
    {
        if (f(v[i]) == 1)
        {
            if (i == count - 1) { count--; }
            else
            {
                for (int j = i + 1; j < count; ++j)
                    v[j - 1] = v[j];
                count--;
                i--;
            }
        }
    }
}

int MyVector::GetCount()
{
    return count;
}

int& MyVector::operator[](int index)
{
    return v[index];
}