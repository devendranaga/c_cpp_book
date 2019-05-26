#include <iostream>
#include <memory>

class shared_class {
    public:
        shared_class()
        {
            std::cout << "created shared class" << std::endl;
        }

        ~shared_class()
        {
            std::cout << "detroy shared class" << std::endl;
        }
};

int main()
{
    {
        std::shared_ptr<shared_class> s = std::make_shared<shared_class>();
    }
    std::cout << "exit program " << std::endl;
}

