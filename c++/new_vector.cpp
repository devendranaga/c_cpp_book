#include <iostream>
#include <vector>

int main()
{
    std::vector<int> *int_v = new std::vector<int>;

    for (auto i = 0; i < 10; i ++) {
        int_v->push_back(i);
    }

    for (auto it = int_v->begin(); it != int_v->end(); it ++) {
        std::cout << *it << std::endl;
    }

    delete int_v;
}

