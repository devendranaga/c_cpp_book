/**
 * Written by Devendra Naga (devendra.aaru@gmail.com)
 *
 * License Apache
 */
#include <iostream>

class library {
    private:
        int bookCount = 100;
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
    private:
        int bookCount = 10;
    public:
        // override the getbookCount method in the library::getBookCount()
        virtual int getBookCount()
        {
            return bookCount;
        }
};

int main()
{
    class engineering e;
    class library l;

    std::cout << "engg book count: " << e.getBookCount() << std::endl;

    std::cout << "library book count: " << l.getBookCount() << std::endl;
}
