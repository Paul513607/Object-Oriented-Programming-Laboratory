#pragma once
class Coleg: public Contact
{
private:
	std::string nrtel;
	std::string adress;
	std::string firma;
public:
	Coleg() { name = nrtel = adress = firma = "Unknown"; } // sau Coleg() = delete; -->daca nu trebuie sa fie "Unknown"
	Coleg(std::string name) { this->name = name; nrtel = adress = firma = "Unknown"; }
	Coleg(std::string name, std::string nrtel, std::string adress, std::string firma)
	{
		this->name = name;
		this->nrtel = nrtel;
		this->adress = adress;
		this->firma = firma;
	}

	void SetNrTel(std::string nrtel) { this->nrtel = nrtel; }
	std::string GetNrTel() const { return this->nrtel; }
	void SetAdress(std::string adress) { this->adress = adress; }
	std::string GetAdress() const { return this->adress; }
	void SetFirma(std::string firma) { this->firma = firma; }
	std::string GetFirma() const { return this->firma; }

	void SetName(std::string name) override { this->name = name; }
	std::string GetName() const override { return this->name; }
	void Print() const override
	{
		std::cout << name << ": " << nrtel << ", " << adress << ", " << firma << '\n';
	}
};