#include <iostream>
#include <string>

int main()
{
    std::string Text { "some text "};

    for (auto it: Text) {
        std::cout << it << std::endl;
    }
}

