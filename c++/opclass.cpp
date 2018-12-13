#include <iostream>

class itemset {
    public:
        itemset operator+(itemset &o)
        {
            itemset n(0);

            n.a = this->a + o.a;

            return n;
        }

        itemset operator-(itemset &o)
        {
            itemset n(0);

            n.a = this->a - o.a;

            return n;
        }

        itemset operator*(itemset &o)
        {
            itemset n(0);

            n.a = this->a * o.a;

            return n;
        }

        itemset operator/(itemset &o)
        {
            itemset n(1);

            n.a = this->a / o.a;

            return n;
        }

        itemset(int v): a(v) {}
        ~itemset() { }

        friend std::ostream & operator<<(std::ostream &os, itemset s);

    private:
        int a;
};

std::ostream & operator<<(std::ostream &os, itemset s)
{
    os << s.a << std::endl;

    return os;
}

int main()
{
    itemset p(4);
    itemset r(4);

    itemset s(0);

    s = p + r;
    std::cout << s;

    s = p - r;
    std::cout << s;

    s = p * r;
    std::cout << s;

    s = p / r;
    std::cout << s;
}

