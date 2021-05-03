#include <iostream>
#include <chrono>

struct Timer
{
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;

	Timer()
	{
		start = std::chrono::high_resolution_clock::now();
	}
	
	~Timer()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		float ms = duration.count() * 1000.0f;
		std::cout << "Duration: " << ms << "ms\n";
	}
};

void function()
{
	Timer tf;
	for (int i = 1; i <= 100; ++i)
		if (true == false) break;
	std::cout << "Time for \"function\": ";
}

int main()
{
	Timer t;
	int k = 0, i;
	for (i = 1; i < 1000; ++i)
		k++;
	function();
	std::cout << "Time for \"program\": ";
	return 0;
}