/**
 * Written by Devendra Naga (devendra.aaru@gmail.com)
 *
 * License Apache
 */
class cons_class {
    public:
        int a;
        
        // constructor definnition
        cons_class(int x)
        {
            a = x;
        }
        
        // copy constructor definition
        cons_class(cons_class &x)
        {
            a = x.a;
        }
};

int main()
{
    cons_class p1 (4); // constructor is called here
    cons_class p2 = p1; // copy constructor called here
}
