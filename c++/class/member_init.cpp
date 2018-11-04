/**
 * Written by Devendra Naga (devendra.aaru@gmail.com)
 *
 * License Apache
 */
#include <iostream>

class simple {
    private:
        int a;
    public:
        simple(int v): a(v)
        {

        }
        int get_val()
        {
            return a;
        }
};


int main()
{
    simple s = 4;

    std::cout << "s.a " << s.get_val() << std::endl;
}
