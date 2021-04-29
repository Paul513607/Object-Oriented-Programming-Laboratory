class Exception1 : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "Index out of bounds!";
	}
};

class Exception2 : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "Missing compare function!";
	}
};

class Exception3 : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "Missing compare class!";
	}
};

class Exception4 : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "List is not sorted. Binary search cannot guarantee a right answer.";
	}
};