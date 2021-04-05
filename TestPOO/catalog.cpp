#include <iostream>
#include <cstring>

#include "student.h"
#include "catalog.h"

Catalog::Catalog()
{
	n = 0;
}

void Catalog::operator+=(const char* s)
{
	Student st;
	int len = strlen(s);
	st.nume = new char[len + 1];
	strcpy_s(st.nume, len + 1, s);
	v[n++] = st;
}

Student& Catalog::operator[](int index)
{
	return v[index];
}

Student& Catalog::operator[](const char* s)
{
	for (int i = 0; i < n; ++i)
		if (strcmp(v[i].GetName(), s) == 0)
			return v[i];
}

int Catalog::GetCount()
{
	return n;
}