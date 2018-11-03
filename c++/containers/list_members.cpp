/**
 * Author Devendra Naga (devendra.aaru@gmail.com)
 *
 * License apache
 */
#include <list>
#include <string>
#include <iostream>

int main(int argc, char **argv)
{
    std::list <std::string> s;
    int i;

    for (i = 1; i < argc; i ++) {

        std::string t = {argv[i]};

        s.push_back(t);
    }

    std::list <std::string> :: const_iterator it;

    std::cout << "print elements " << std::endl;

    for (it = s.begin(); it != s.end(); it ++) {
        std::cout << "it " << *it << std::endl;
    }


    return 0;
}

