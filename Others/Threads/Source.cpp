#include <iostream>
#include <thread>
#include <chrono>
#include "Timer.h"

int k = 0;

void Work()
{
	using namespace std::literals::chrono_literals;
	printf("Current thread id is: %d\n", std::this_thread::get_id());
	for (int i = 1; i <= 20; ++i)
	{
		k++;
		std::this_thread::sleep_for(1ms);
	}
}

int main()
{
	Timer t;
	std::thread worker(Work);

	printf("Current thread id is: %d\n", std::this_thread::get_id());
	int p = 0;
	for (int i = 1; i <= 10; ++i)
		p++;
	worker.join();
	printf("Finished!\np = %d\nk = %d\n", p, k);
	return 0;
}