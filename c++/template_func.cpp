#include <iostream>

template <typename T>
T add(T a, T b)
{
    return a + b;
}

template <typename T1, typename T2>
T1 add(T1 a, T2 b)
{
    return a + b;
}

int main()
{
    int a = 4;
    int b = 5;

    std::cout << "add(int " << a << ", int " << b << ") " << add<int, int>(a, b) << std::endl;

    double a1 = 4.4;
    double a2 = 5.5;

    std::cout << "add(double " << a1 << ", double " << a2 << ") " << add<double, double>(a1, a2) << std::endl;

    std::cout << "add(double " << a1 << ", int " << a << ") " << add<double, int>(a1, a) << std::endl;

    std::cout << "add(int " << a1 << ", double " << b << ") " << add<double, int>(a1, b) << std::endl;
    std::cout << "add(int " << a << ", double " << a2 << ") " << add<int, double>(a, a2) << std::endl;

}

