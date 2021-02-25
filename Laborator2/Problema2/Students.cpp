#include "Students.h"
#include <cstring>

Student Student::Init()
{
    strcpy(name,"");
    math_grade=english_grade=history_grade=0;
}

void Student::SetName(char s[])
{
    if (strlen(s)>50) return;
    strcpy(name,s);
}

void Student::SetMathGrade(unsigned x)
{
    if (x<1 || x>10) return;
    math_grade=x;
}

void Student::SetEnglishGrade(unsigned x)
{
    if (x<1 || x>10) return;
    english_grade=x;
}

void Student::SetHistoryGrade(unsigned x)
{
    if (x<1 || x>10) return;
    history_grade=x;
}

char* Student::GetName()
{
    char *p=name;
    return p;
}

unsigned Student::GetMathGrade()
{
    return math_grade;
}

unsigned Student::GetEnglishGrade()
{
    return english_grade;
}

unsigned Student::GetHistoryGrade()
{
    return history_grade;
}

float Student::GetAverageGrade()
{
    float x=(math_grade+english_grade+history_grade)/3.0f;
    return x;
}
