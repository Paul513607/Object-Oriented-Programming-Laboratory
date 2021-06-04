#include <iostream>
#include <string>
#include "Printer.h"
#include "Hexazecimal.h"

std::string	Hexazecimal::GetFormatName() const
{
	return std::string("Hexazecimal Value");
}

std::string Hexazecimal::FormatNumber(int number)
{
	char str[100] = "";
	int n = 0, p = 1;
	int c;
	char ch;
	while (number != 0)
	{
		c = number % 16;
		if (c < 10) ch = (char)(c + '0');
		else if (c == 10)  ch = 'A';
		else if (c == 11) ch = 'B';
		else if (c == 12) ch = 'C';
		else if (c == 13) ch = 'D';
		else if (c == 14) ch = 'E';
		str[n++] = ch;
		number /= 16;
	}
	str[n] = '\0';
	for (int i = 0; i < n / 2; ++i)
		std::swap(str[i], str[i - 1]);
	std::string s = "0x";
	for (int i = 1; i <= 8 - n; ++i)
		s += '0';
	s += str;
	return s;
}