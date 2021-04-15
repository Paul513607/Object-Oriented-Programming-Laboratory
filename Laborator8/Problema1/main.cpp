#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <sstream>
#include <fstream>

#define mapIter std::map<const std::string, int>::iterator

class myCompare
{
public:
	bool operator() (mapIter it1, mapIter it2) const
	{
		return (it1->second < it2->second || (it1->second == it2->second && it1->first > it2->first));
	}
};

std::string to_lower(std::string s)
{
	int i,n=s.size();
	for (i = 0; i < n; ++i)
		if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
	return s;
}

int main()
{
	int i;
	std::ifstream fin("input.txt");
	std::stringstream strStream;
	std::string text, s;
	std::map<const std::string, int> mapper;
	mapIter it;
	std::priority_queue<mapIter, std::vector<mapIter>, myCompare> myqueue;
	strStream << fin.rdbuf();
	text = strStream.str();
	
	while (!text.empty())
	{
		i = text.find_first_of(" ,?!.", 0);
		s = text.substr(0, i);
		s = to_lower(s);
		text.erase(0, i);
		i = text.find_first_not_of(" ,?!.", 0);
		text.erase(0, i);
		it = mapper.find(s);
		if (it == mapper.cend()) mapper[s] = 1;
		else it->second++;
	}

	for (it = mapper.begin(); it != mapper.end(); ++it)
		myqueue.push(it);

	while (!myqueue.empty())
	{
		it = myqueue.top();
		std::cout << it->first << " => " << it->second << '\n';
		myqueue.pop();
	}
	fin.close();
	return 0;
}

// I bought an apple. Then I eat an apple. Apple is my favorite.