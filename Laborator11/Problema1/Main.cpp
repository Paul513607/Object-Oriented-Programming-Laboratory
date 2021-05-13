#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>

int main()
{
	std::vector<std::string> v = { "bass", "zuf", "trog", "potoa", "matatata", "argo" };
	auto f = [](std::string s1, std::string s2) {return (s1.size() > s2.size() || (s1.size() == s2.size() && s1 < s2)); };
	std::sort(v.begin(), v.end(), f);
	for (auto it : v)
	{
		std::cout << it << "\n";
	}
	return 0;
}