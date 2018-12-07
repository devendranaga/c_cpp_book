#include <iostream>
#include <typeinfo>

template <typename T>
void template_func(T a)
{
    std::cout << typeid(a).name() << std::endl;
    if (typeid(int).name() == typeid(a).name()) {
        std::cout << "integer" << std::endl;
    }

    if (typeid(float).name() == typeid(a).name()) {
        std::cout << "float" << std::endl;
    }

    if (typeid(double).name() == typeid(a).name()) {
        std::cout << "double" << std::endl;
    }

    if (typeid(char *).name() == typeid(a).name()) {
        std::cout << "string" << std::endl;
    }

}

int main()
{
    template_func(4);
    template_func(4.1);
}

