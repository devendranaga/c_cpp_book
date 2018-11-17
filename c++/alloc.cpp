#include <iostream>

int main()
{
    int *ptr;

    ptr = new int;
    if (ptr == nullptr) {
        std::cout << "cannot allocate integer " << std::endl;
        return -1;
    }

    *ptr = 4;

    std::cout << "value at ptr " << *ptr << std::endl;

    return 0;
}

