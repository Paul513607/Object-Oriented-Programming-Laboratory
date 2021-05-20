#pragma once
class Contact
{
protected:
	std::string name;
public:
	virtual void SetName(std::string name) = 0;
	virtual std::string GetName() const = 0;
	virtual void Print() const = 0;
	virtual ~Contact() = default;
};

enum class Contacte
{
	Prieten, Cunoscut, Coleg
};