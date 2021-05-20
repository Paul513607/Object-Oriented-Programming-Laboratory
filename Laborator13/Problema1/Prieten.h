#pragma once
class Prieten : public Contact
{
private:
	std::string nrtel;
	std::string adress;
	std::string date_of_birth;
public:
	Prieten() { name = nrtel = adress = date_of_birth = "Unknown"; }
	Prieten(std::string name) { this->name = name; nrtel = adress = date_of_birth = "Unknown"; }
	Prieten(std::string name, std::string nrtel, std::string adress, std::string date)
	{
		this->name = name;
		this->nrtel = nrtel;
		this->adress = adress;
		this->date_of_birth = date;
	}

	void SetNrTel(std::string nrtel) { this->nrtel = nrtel; }
	std::string GetNrTel() const { return this->nrtel; }
	void SetAdress(std::string adress) { this->adress = adress; }
	std::string GetAdress() const { return this->adress; }
	void SetDateofBirth(std::string date) { this->date_of_birth = date; }
	std::string GetDateofBirth() const { return this->name; }

	void SetName(std::string name) override { this->name = name; }
	std::string GetName() const override { return this->name; }
	void Print() const override
	{
		std::cout << name << ": " << nrtel << ", " << adress << ", " << date_of_birth << '\n';
	}
};