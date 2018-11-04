/**
 * Author: Devendra Naga (devendra.aaru@gmail.com)
 *
 * License Apache
 */
#include <iostream>

class library {
    private:
        // automatic default initialisation of the class members..
        // C++ allows this kind of initialisation
        // or this could be initialised in the constructor call
        int bookCount = 4;
    public:
        // get total number of books
        int getBookCount()
        {
            return bookCount;
        }
        int getAccess()
        {
            return true;
        }
};

int main()
{
    class library l;

    std::cout << "library book count: " << l.getBookCount() << std::endl;
}
