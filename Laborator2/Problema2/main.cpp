#include <iostream>
#include <cstring>
#include <iomanip>
#include "Students.h"
#include "GlobalFunc.h"

using namespace std;

int main()
{
    Student s1,s2;
    s2.Init();
    s1.SetName("John McCool");
    s2.SetName("John McBad");

    s1.SetMathGrade(6);
    s2.SetMathGrade(8);

    s1.SetEnglishGrade(10);
    s2.SetEnglishGrade(9);

    s1.SetMathGrade(0);

    s1.SetHistoryGrade(12);
    s1.SetHistoryGrade(8);

    s2.SetHistoryGrade(8);

    cout << "Student " << s1.GetName() << " has a Math grade of " << s1.GetMathGrade() << " and an English grade of " << s1.GetEnglishGrade() << '\n';
    cout << "Student " << s2.GetName() << " has a History grade of " << s2.GetHistoryGrade() << " and an average grade of " << fixed << setprecision(2) << s2.GetAverageGrade() << '\n';
    cout << CompareAlphabetically(s1,s2) << '\n';
    cout << CompareMathGrade(s1,s2) << '\n';
    cout << CompareEnglishGrade(s1,s2) << '\n';
    cout << CompareHistoryGrade(s1,s2) << '\n';
    cout << CompareAverageGrade(s1,s2) << '\n';
    return 0;
}
