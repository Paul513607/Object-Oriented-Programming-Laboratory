#include "Students.h"
#include "GlobalFunc.h"
#include <cstring>

int CompareAlphabetically(Student s1, Student s2)     //Cu functii friend
{
    if (strcmp(s1.name,s2.name)==0) return 0;
    else if (strcmp(s1.name,s2.name)>0) return 1;
    else return -1;
}

int CompareMathGrade(Student s1, Student s2)
{
    if (s1.math_grade>s2.math_grade) return 1;
    else if (s1.math_grade==s2.math_grade) return 0;
    else return -1;
}

int CompareEnglishGrade(Student s1, Student s2)
{
    if (s1.english_grade>s2.english_grade) return 1;
    else if (s1.english_grade==s2.english_grade) return 0;
    else return -1;
}

int CompareHistoryGrade(Student s1, Student s2)
{
    if (s1.history_grade>s2.history_grade) return 1;
    else if (s1.history_grade==s2.history_grade) return 0;
    else return -1;
}

int CompareAverageGrade(Student s1, Student s2)
{
    float x,y;
    x=s1.GetAverageGrade();
    y=s2.GetAverageGrade();
    if (x>y) return 1;
    else if (x==y) return 0;
    else return -1;
}

/*
void del_letter(char s[], int i)        //Cu functii de Get
{
    int j;
    for (j=i+1; s[j]; ++j)
        s[j-1]=s[j];
    s[j-1]='\0';
}

void lowercase_nospaces(char s[])
{
    int i;
    char aux[50];
    for (i=0; s[i]; ++i)
    {
        if (s[i]>='A' && s[i]<='Z') s[i]+=32;
        else if (s[i]==' ' || s[i]=='-') {del_letter(s,i); i--;}
    }
}

int CompareAlphabetically(Student s1, Student s2)
{
    char *a=s1.GetName();
    char *b=s2.GetName();
    lowercase_nospaces(a);
    lowercase_nospaces(b);
    if (strcmp(a,b)==0) return 0;
    else if (strcmp(a,b)>0) return 1;
    else return -1;
}

int CompareMathGrade(Student s1, Student s2)
{
    unsigned x,y;
    x=s1.GetMathGrade();
    y=s2.GetMathGrade();
    if (x>y) return 1;
    else if (x==y) return 0;
    else return -1;
}

int CompareEnglishGrade(Student s1, Student s2)
{
    unsigned x,y;
    x=s1.GetEnglishGrade();
    y=s2.GetEnglishGrade();
    if (x>y) return 1;
    else if (x==y) return 0;
    else return -1;
}

int CompareHistoryGrade(Student s1, Student s2)
{
    unsigned x,y;
    x=s1.GetHistoryGrade();
    y=s2.GetHistoryGrade();
    if (x>y) return 1;
    else if (x==y) return 0;
    else return -1;
}
*/
