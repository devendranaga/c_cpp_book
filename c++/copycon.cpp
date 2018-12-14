#include <iostream>

class copy_constr {
    public:
        copy_constr(int a) : v(a) { }

        copy_constr(copy_constr &s) {
            v = s.v;
        }

        int get_v() { return v; }

    private:
        int v;
};

int main()
{
    copy_constr a(4);
    copy_constr a1(a);
    copy_constr a11 { a1 };

    std::cout << "a.v: " << a.get_v() << "  a1.v: " << a1.get_v() << "   a2.v: " << a11.get_v() << std::endl;
}

