#include <iostream>
#include <cstring>

class Something
{
private:
	int x, y, z;
	char* str;
public:
	Something() : x(0), y(0), z(0), str(nullptr) { printf("Constructed1!\n"); }
	Something(int x, int y, int z, const char* name) : x(x), y(y), z(z) 
	{
		str = const_cast<char*>(name);
		printf("Constructed2!\n");
	}

	Something(const Something& smth)				// lvalue reference
	{
		x = smth.x;
		y = smth.y;
		z = smth.z;
		int len = strlen(smth.str);
		str = new char[len + 1];
		strcpy_s(str, len + 1, smth.str);
		printf("\nCopy constructor called.\n\n");
	}
	Something(Something&& smth)	noexcept			// rvalue reference
	{
		x = smth.x;
		y = smth.y;
		z = smth.z;
		str = smth.str;
		smth.str = nullptr;
		printf("\nMove constructor called.\n\n");
	}

	Something& operator=(const Something& smth)		// lvalue reference
	{
		x = smth.x;
		y = smth.y;
		z = smth.z;
		int len = strlen(smth.str);
		str = new char[len + 1];
		strcpy_s(str, len + 1, smth.str);
		printf("\nCopy assignment operator called.\n\n");
		return (*this);
	}

	Something& operator=(Something&& smth) noexcept // rvalue reference
	{
		x = smth.x;
		y = smth.y;
		z = smth.z;
		str = nullptr;
		str = smth.str;
		smth.str = nullptr;
		printf("\nMove assignment operator called.\n\n");
		return (*this);
	}

	friend Something operator+(const Something& smth1, const Something& smth2)
	{
		int len = strlen(smth1.str) + strlen(smth2.str);
		char* name = new char[len + 1];
		strcpy_s(name, len + 1, smth1.str);
		strcat_s(name, len + 1, smth2.str);
		Something temp(smth1.x + smth2.x, smth1.y + smth2.y, smth1.z + smth2.z, name);
		return temp;
	}

	void Print()
	{
		std::cout << x << " " << y << " " << z << " " << str << '\n';
	}

	~Something()
	{
		delete[] str;
		printf("Destroyed!\n");
	}
};

int main()
{
	Something person1(2,4,6,"Papa"), person2(1,2,3,"John");

	Something smth1(person1);				// lvalue
	Something smth2(person1 + person2);		// rvalue
	smth1.Print();
	smth2.Print();

	person1 = smth2;						// lvalue
	person2 = smth1 + smth2;				// rvalue
	person1.Print();
	person2.Print();

	return 0;
}