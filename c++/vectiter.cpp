#include <iostream>
#include <vector>

void printVector(std::vector<std::string> data)
{
    std::vector<std::string>::const_iterator it;

    for (it = data.begin(); it != data.end(); it ++) {
        std::cout << *it << std::endl;
    }
}

int main()
{
    std::vector<std::string> msgs;

    msgs.insert(msgs.end(), "Hi");
    msgs.insert(msgs.end(), "hello");

    msgs.insert(msgs.begin(), "first msg");

    printVector(msgs);

    return 0;
}

