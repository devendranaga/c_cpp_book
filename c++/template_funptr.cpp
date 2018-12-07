#include <iostream>

template<typename T>
struct Functs {
    typedef void (*setCallback)(T t);
    typedef T (*getCallback)(void);
};

class template_class {
    private:
        Functs<int>::setCallback t;
        Functs<int>::getCallback g;

    public:
        template_class() { };
        ~template_class() { };

        void set(Functs<int>::setCallback t1)
        {
            t = t1;
        }

        void get(Functs<int>::getCallback g1)
        {
            g = g1;
        }

        void setget()
        {
            t(4);
            g();
        }
};

void set(int a)
{
    std::cout << "set callback " << a << std::endl;
}

int get(void)
{
    std::cout << "get callback" << std::endl;
}

int main()
{
    template_class t;

    t.set(set);

    t.get(get);

    t.setget();

    return 0;
}

