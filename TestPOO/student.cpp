#include <iostream>
#include <cstring>

#include "student.h"
#include "catalog.h"

Student::Student()
{
	count = 0;
	nume = nullptr;
}

Student::Student(char* nume)
{
	count = 0;
	int len = strlen(nume) + 1;
	this->nume = new char[len + 1];
	strcpy_s(this->nume, len + 1, nume);
}

char* Student::GetName()
{
	return nume;
}

void Student::PrintNote()
{
	for (int i = 0; i < count; ++i)
	{
		std::cout << "\t" << materia[i] << " => " << note[i] << "\n";
	}
}

int& Student::operator[](const char* s)
{
	for (int i = 0; i < count; ++i)
	{
		if (strcmp(materia[i], s) == 0) { return note[i]; }
	}
	int len = strlen(s);
	materia[count] = new char[len + 1];
	strcpy_s(materia[count], len + 1, s);
	count++;
	return note[count - 1];
}

Student::operator float()
{
	float sum=0;
	for (int i = 0; i < count; ++i)
		sum += note[i];
	return sum / count;
}