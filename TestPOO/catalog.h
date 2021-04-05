class Catalog
{
protected:
	int n;
	Student v[101];
public:
	Catalog();
	Student& operator[](int index);
	Student& operator[](const char* s);
	void operator+=(const char* s);
	int GetCount();
};