#include <iostream>

int add(int a, int b = 4)
{
	return a + b;
}

int main()
{
	std::cout << "add result " << add(4) << std::endl;
	std::cout << "add result " << add(4, 8) << std::endl;
}

