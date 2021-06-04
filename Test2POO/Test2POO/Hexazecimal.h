#pragma once
class Hexazecimal : public Printer
{
public:
	std::string GetFormatName() const override;
	std::string FormatNumber(int number) override;
};

