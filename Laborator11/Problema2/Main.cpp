#include <iostream>
#include <list>

int main()
{
	std::list<int> list1 = { 8,2,13,9,16,2,10,4 };
	auto maxim = [](std::list<int> ls) 
	{
		int max = *ls.begin();
		auto it = ls.begin();
		it++;
		for (; it != ls.end(); ++it)
			if (*it > max) max = *it;
		return max;
	};

	std::cout << maxim(list1);
	return 0;
}