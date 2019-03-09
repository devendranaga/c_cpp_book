/**
 * Author: Devendra Naga (devendra.aaru@gmail.com)
 * License Apache
 */
#include <iostream>

struct s {
    private:
        int a;
    public:
        s() { a = 0; }
        ~s() { }

        int get_a()
        {
            return a;
        }

        void set_a(int a1)
        {
            a = a1;
        }
};

int main()
{
    s obj;

    obj.set_a(4);

    std::cout << obj.get_a() << std::endl;
}

