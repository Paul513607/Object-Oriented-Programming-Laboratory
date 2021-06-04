#pragma once
class Printer
{
public:
	virtual std::string GetFormatName() const = 0;
	virtual std::string FormatNumber(int number) = 0;
};