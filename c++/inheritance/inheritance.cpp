/**
 * Written by Devendra Naga (devendra.aaru@gmail.com)
 *
 * License Apache
 */
#include <iostream>

class library {
    private:
        int bookCount = 4;
    public:
        int getBookCount()
        {
            return bookCount;
        }
        int getAccess()
        {
            return true;
        }
};


class engineering : public library {
};

class compsci: public engineering, public library {
};

int main()
{
    engineering e;
    library l;
    computersci cs;

    std::cout << "book count: " << e.getBookCount() << std::endl;

    std::cout << "library book count: " << l.getBookCount() << std::endl;
}
