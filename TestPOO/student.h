class Student
{
private:
	char* nume;
	int count;
	char* materia[100];
	int note[100];
public:
	friend class Catalog;
	Student();
	Student(char *nume);
	char* GetName();
	void PrintNote();
	int& operator[](const char* s);
	operator float();
};