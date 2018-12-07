#include <iostream>

template <typename T>
class calculator {
    public:
        T add(T a, T b)
        {
            return a + b;
        }
        T sub(T a, T b)
        {
            return a - b;
        }

        T divide(T a, T b)
        {
            if (b == 0)
                throw std::runtime_error("b is 0");

            return a / b;
        }

        T multiply(T a, T b)
        {
            return a * b;
        }
};

int main()
{
    int a = 4, b = 4;
    int res;

    double a2 = 4.1, b2 = 4.1;
    double res2;

    calculator<int> c;

    std::cout << "test integers" << std::endl;

    res= c.add(a, b);
    std::cout << "add " << res << std::endl;

    res = c.sub(a, b);
    std::cout << "sub " << res << std::endl;

    res = c.divide(a, b);
    std::cout << "divide " << res << std::endl;

    res = c.multiply(a, b);
    std::cout << "multiply " << res << std::endl;


    calculator<double> c2;

    std::cout << "test doubles" << std::endl;

    res2 = c2.add(a2, b2);
    std::cout << "add " << res2 << std::endl;

    res2 = c2.sub(a2, b2);
    std::cout << "sub " << res2 << std::endl;

    res2 = c2.divide(a2, b2);
    std::cout << "divide " << res2 << std::endl;

    res2 = c2.multiply(a2, b2);
    std::cout << "multiply " << res2 << std::endl;
}

