/**
 * Written by Devendra Naga (devendra.aaru@gmail.com)
 * 
 * License Apache
 */
#include <iostream>
#include <map>

int main()
{
    std::map<char,int> m;
    std::map<char,int> :: iterator t;

    m['a'] = 1;
    m['b'] = 2;
    m['c'] = 3;
    m['d'] = 4;

    std::cout << "map size:" << m.size() << std::endl;

    for (t = m.begin(); t != m.end(); t ++) {
        std::cout << "keyid:" << t->first
                  << "value:" << t->second << std::endl;
    }

    // search for d
    std::map<char, int> :: iterator t_1;

    t_1 = m.find('d');

    std::cout << "value at 'd':"<< t_1->second << std::endl;
}
