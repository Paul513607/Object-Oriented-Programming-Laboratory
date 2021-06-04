#pragma once
class Decimal : public Printer
{
public:
	std::string GetFormatName() const override;
	std::string FormatNumber(int number) override;
};

