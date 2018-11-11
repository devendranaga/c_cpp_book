#include <iostream>

int main()
{
	bool a = 11;

	std::cout << std::boolalpha << "a is  " << a << std::endl;

	a = -11;

	std::cout << std::boolalpha << "a is " << a << std::endl;

	a = 0;

	std::cout << std::boolalpha << "a is " << a << std::endl;
}

