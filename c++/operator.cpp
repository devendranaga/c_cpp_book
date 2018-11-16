#include <iostream>

class arithmetic {
    private:
        int a;
        int b;

    public:

        arithmetic(int a_, int b_) : a(a_), b(b_) { }

        int operator+()
        {
            return a + b;
        }
};

int main()
{
    arithmetic a(1 , 2);

    std::cout << a+ <<std::endl;
}


