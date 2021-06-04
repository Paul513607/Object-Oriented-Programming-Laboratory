#include <iostream>
#include <array>
#include <string>
#include "Printer.h"
#include "Hexazecimal.h"
#include "Decimal.h"
#include "Number.h"

Number::Number(int value)
{
	number = value;
	count = 0;
}

Number::operator int()
{
	return number;
}

Number operator+(Number n1, Number n2)
{
	n1.number += n2.number;
	return n1;
}

Number operator-(Number n1, Number n2)
{
	n1.number -= n2.number;
	return n1;
}

Number operator*(Number n1, Number n2)
{
	n1.number *= n2.number;
	return n1;
}

Number operator/(Number n1, Number n2)
{
	n1.number /= n2.number;
	return n1;
}

Number& Number::operator+=(Printer* prnt)
{
	v[count] = prnt;
	count++;
	return *this;
}

void Number::Print() const
{
	int i;
	for (i = 0; i < count; ++i)
	{
		std::cout << "Format: " << v[i]->GetFormatName() << ": " << v[i]->FormatNumber(this->number) << '\n';
	}
}