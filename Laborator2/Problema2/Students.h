class Student
{
private:
    char name[50];
    unsigned math_grade,english_grade,history_grade;
public:
    Student Init();
    void SetName(char s[]);
    void SetMathGrade(unsigned x);
    void SetEnglishGrade(unsigned x);
    void SetHistoryGrade(unsigned x);
    char* GetName();
    unsigned GetMathGrade();
    unsigned GetEnglishGrade();
    unsigned GetHistoryGrade();
    float GetAverageGrade();

    friend int CompareAlphabetically(Student s1,Student s2);
    friend int CompareMathGrade(Student s1,Student s2);
    friend int CompareEnglishGrade(Student s1,Student s2);
    friend int CompareHistoryGrade(Student s1,Student s2);
    friend int CompareAverageGrade(Student s1,Student s2);

};
