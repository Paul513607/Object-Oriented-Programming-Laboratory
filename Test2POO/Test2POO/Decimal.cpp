#include <iostream>
#include <string>
#include "Printer.h"
#include "Decimal.h"

std::string Decimal::GetFormatName() const
{
	return std::string("Decimal Value");
}

std::string Decimal::FormatNumber(int number)
{
	int nr = 0, c;
	int p = 1;
	while (number != 0)
	{
		c = number % 10;
		nr = nr + c * p;
		p = p * 10;
		number = number / 10;
	}
	std::string s = std::to_string(nr);
	return s;
}