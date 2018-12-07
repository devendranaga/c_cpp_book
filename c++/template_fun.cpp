#include <iostream>

template <typename T>
struct Functs {
    typedef void (*type)(T t);
};

void type_f(int t)
{
    std::cout << t << std::endl;
}

int main()
{
    Functs<int>::type t;

    t = type_f;

    t(4);
}

