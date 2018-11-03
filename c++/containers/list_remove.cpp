/**
 * Author Devendra Naga (devendra.aaru@gmail.com)
 *
 * License apache
 */
#include <list>
#include <string>
#include <iostream>

std::list<std::string>::const_iterator
find_element(std::list<std::string> &s, std::string _s)
{
    std::list <std::string> :: const_iterator it;

    for (it = s.begin(); it != s.end(); it ++) {
        if (*it == _s) {
            return it;
        }
    }

    return s.end();
}

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

    i = 0;

    for (it = s.begin(); it != s.end(); it ++) {
        std::cout << "it " << *it << std::endl;
    }


    std::list <std::string> :: const_iterator it1;

    it1 = find_element(s, "hello");
    if (it1 != s.end()) {
        std::cout << "element found " << *it1 << std::endl;
        s.erase(it1);


        for (it = s.begin(); it != s.end(); it ++) {
            std::cout << "it " << *it << std::endl;
        }
    } else {
        std::cout << "element could not found" << std::endl;
    }

    return 0;
}

