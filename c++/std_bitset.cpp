/**
 * Author: Devendra Naga (devendra.aaru@gmail.com)
 * 
 * License: Apache
 */
#include <iostream>
#include <bitset>

int main()
{
    std::bitset<2> a("00");

    std::cout << "a is " << a << std::endl;

    int i;

    std::cout << "iterate over bits " << std::endl;
    for (i = 0;  i < a.size(); i ++) {
        std::cout << "a[" << i << "] " << a[i] << std::endl;
        if (a.test(i)) {
            std::cout << "bit pos " << i << " is set" << std::endl;
        }
    }

    std::cout << "set all bits .. " << std::endl;
    for (i = 0 ; i < a.size(); i ++) {
        a.set(i);
    }

    std::cout << "number of bits being set " << a.count() << std::endl;

    // test if no bits are being set
    if (a.none()) {
        std::cout << "no bits are set in a " << a << std::endl;
    }

    // test if any bit is set
    if (a.any()) {
        std::cout << "atleat one bit is being set in a " << a << std::endl;
    }

    if (a.all()) {
        std::cout << "all bits are set in a " << a << std::endl;
    }

    std::cout << "reset all bits .." << std::endl;

    for (i = 0; i < a.size(); i ++) {
        a.reset(i);
    }

    std::cout << "number of bits being set " << a.count() << std::endl;

    std::cout << "rep in string format " << a.to_string() << std::endl;

    return 0;
}

