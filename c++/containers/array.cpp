#include <iostream>
#include <array>

int main()
{
    std::array <int, 4> a;
    int i;

    for (i = 0; i < 4; i ++) {
        a[i] = i;
    }

    std::array <int, 4> :: const_iterator it;

    i = 0;
    for (it = a.begin(); it != a.end(); it ++) {
        std::cout << " array[" << i << "]" << "  " << *it << std::endl;
    }

    return 0;
}

