#include <iostream>

int main()
{
    std::cout << std::boolalpha << " true statement " << true << std::endl;

    // any statements printed after std::boolalpha will be printed in text
    bool t = true;

    std::cout << " true " << t << std::endl;

    return 0;
}

