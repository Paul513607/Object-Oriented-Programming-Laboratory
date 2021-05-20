#include <iostream>
#include <list>
#include <string>
#include "Contact.h"
#include "Prieten.h"
#include "Cunoscut.h"
#include "Coleg.h"
#include "Agenda.h"

int main()
{
	Agenda oameni;
	oameni.AddContact(new Coleg("George", "0765518949", "Str. Florilor Nr. 12", "George's Butchery"));
	oameni.AddContact(new Cunoscut("Karl", "0784117736"));
	oameni.AddContact(new Prieten("Fred", "0746378824", "Str. Aricilor Nr. 22", "04.05.1995"));
	oameni.AddContact(new Coleg("John"));
	oameni.AddContact(new Prieten("Glen", "0748204802", "Str. Ploii Nr. 5", "18.10.1998"));
	Contact* tmp = oameni.SearchByName("Fred");

	if (typeid(*tmp) == typeid(Prieten)) std::cout << "Prieten:\n";
	else if (typeid(*tmp) == typeid(Cunoscut)) std::cout << "Cunoscut:\n";
	else if (typeid(*tmp) == typeid(Coleg)) std::cout << "Coleg:\n";

	/*
	if (Prieten* p = dynamic_cast<Prieten*> (tmp))
		p->Print();
	else
		std::cout << "No conversion possible.\n";
	*/

	tmp->Print();
	std::cout << '\n';
	std::list<Prieten> ls = oameni.PrieteniList();
	for (auto it : ls)
		it.Print();
	std::cout << '\n';
	oameni.DeleteContact("John");
	oameni.Print();
	return 0;
}