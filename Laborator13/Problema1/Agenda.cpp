#include <iostream>
#include <list>
#include <string>
#include "Contact.h"
#include "Prieten.h"
#include "Cunoscut.h"
#include "Coleg.h"
#include "Agenda.h"

Contact* Agenda::SearchByName(std::string nume)
{
	for (auto it : contacte)
	{
		if (nume == it->GetName())
			return it;
	}
	return nullptr;
}

std::list<Prieten> Agenda::PrieteniList() const
{
	std::list<Prieten> prieteni;
	for (auto it : contacte)
		if (typeid(*it) == typeid(Prieten))
		{
			Prieten* p = static_cast<Prieten*> (it);
			prieteni.push_back(*p);
		}
	// Echivalente
	/*
	Prieten* p;
	for (auto it : contacte)
		if (p = dynamic_cast<Prieten*> (it))
			prieteni.push_back(*p);
	*/

	return prieteni;
}

bool Agenda::DeleteContact(std::string nume)
{
	for (auto it : contacte)
	{
		if (nume == it->GetName())
		{
			contacte.remove(it);
			return true;
		}
	}
	return false;
}

void Agenda::AddContact(Contact* c)
{
	contacte.push_back(c);
}

void Agenda::Print() const
{
	for (auto it : contacte)
		it->Print();
}