#pragma once
class Cunoscut : public Contact
{
private:
	std::string nrtel;
public:
	Cunoscut() { name = nrtel = "Unknown"; }
	Cunoscut(std::string name) { this->name = name; nrtel = "Unknown"; }
	Cunoscut(std::string name, std::string nrtel)
	{
		this->name = name;
		this->nrtel = nrtel;
	}

	void SetNrTel(std::string nrtel) { this->nrtel = nrtel; }
	std::string GetNrTel() const { return this->nrtel; }

	void SetName(std::string name) override { this->name = name; }
	std::string GetName() const override { return this->name; }
	void Print() const override
	{
		std::cout << name << ": " << nrtel << '\n';
	}
};