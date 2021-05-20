#pragma once
class Agenda
{
private:
	std::list<Contact*> contacte;
public:
	Contact* SearchByName(std::string nume);
	std::list<Prieten> PrieteniList() const;
	bool DeleteContact(std::string nume);
	void AddContact(Contact* c);
	void Print() const;
};

