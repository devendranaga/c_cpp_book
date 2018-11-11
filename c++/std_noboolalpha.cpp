#include <iostream>

int main()
{
    std::cout << std::boolalpha << "true in string is " << true << std::endl
                                << " false in string is " << false << std::endl;

    std::cout << true << std::endl;

    std::cout << std::noboolalpha << "true in string is " << true << std::endl
                                  << " false in string is " << false << std::endl;

    std::cout << false << std::endl;

    return 0;
}

