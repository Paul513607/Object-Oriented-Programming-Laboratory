#pragma once
class Number
{
private:
	Printer* v[100];
	int number;
	int count;
public:
	Number(int value);
	operator int();
	friend Number operator+(Number n1, Number n2);
	friend Number operator-(Number n1, Number n2);
	friend Number operator*(Number n1, Number n2);
	friend Number operator/(Number n1, Number n2);
	Number& operator+=(Printer* prnt);
	void Print() const;
};

