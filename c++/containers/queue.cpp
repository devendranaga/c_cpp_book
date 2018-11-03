/**
 * Author: Devendra Naga (devendra.aaru@gmail.com)
 *
 * License Apache
 */
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

    // lets print the size of the queue
    std::cout << "queue size " << a.size() << std::endl;

    // till the queue is empty display the first element of the
    // queue and then pop it
    while (!a.empty()) {
        std::cout << "queue[" << i << "]"<< " " << a.front() << std::endl;
        i ++;

        // pop the elements till the queue is flushed
        a.pop();
    }

    return 0;
}

