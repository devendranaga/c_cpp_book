/**
 * Author: Devendra Naga (devendra.aaru@gmail.com)
 *
 * License Apache
 */
#include <iostream>

class cls {
    int p;

    int getP()
    {
        return (p = 4);
    }
};

int main()
{
    cls p;

    std::cout << p.getP() << std::endl;
}
