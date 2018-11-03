#include <queue>
#include <iostream>

int main()
{
    int i;
    std::queue<int> a;

    for (i = 0; i < 4; i ++) {
        a.push(i);
    }

    i = 0;

    while (!a.empty()) {
        std::cout << "queue[" << i << "]"<< " " << a.front() << std::endl;
        i ++;
        a.pop();
    }

    return 0;
}

