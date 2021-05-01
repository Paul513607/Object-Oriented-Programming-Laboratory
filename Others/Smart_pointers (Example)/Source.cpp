#include <iostream>
#include <memory>

class Something
{
	int x, y;
public:
	Something() : x(0), y(0)
	{
		printf("Created Something!\n");
	}
	Something(int x, int y) : x(x), y(y)
	{
		printf("Created Something!\n");
	}
	~Something()
	{
		printf("Destroyed Something!\n");
	}

	void Print()
	{
		std::cout << x << " " << y << '\n';
	}

	int GetX() const { return x; }
	int GetY() const { return y; }

	void SetX(const int& x) { this->x = x; }
	void SetY(const int& y) { this->y = y; }
};
int main()
{
	{
		//std::unique_ptr<Something> uniqSmth(new Something(1, 2));
		std::unique_ptr<Something> uniqSmth = std::make_unique<Something>(1, 2);
		uniqSmth->SetX(10);
		std::cout << uniqSmth->GetY() << '\n';
		uniqSmth->Print();
	}

	{
		std::weak_ptr<Something> weakSmth;
		{
			std::shared_ptr<Something> sharedSmth1;
			{
				std::shared_ptr<Something> sharedSmth2 = std::make_shared<Something>();
				sharedSmth1 = sharedSmth2;
				sharedSmth1->SetY(20);
				sharedSmth2->Print();
				weakSmth = sharedSmth2;
			}
			sharedSmth1->SetX(15);
			sharedSmth1->Print();
		}
		if (weakSmth.expired()) std::cout << "Expired weak_ptr.\n";
	}
	return 0;
}