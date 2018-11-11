#include <iostream>

int add(int a = 4, int b = 4, int c = 4)
{
	return a + b + c;
}

int main()
{
	std::cout << " add result " << add(4) << std::endl;
}

