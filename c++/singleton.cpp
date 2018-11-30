#include <iostream>

class Singleton {
    private:
        int var;
        static Singleton *instance;

    public:
        Singleton()
        {
            var = 4;
        }
        int getVar()
        {
            return var;
        }

        void setVar(int v)
        {
            var = v;
        }

        static Singleton *getInstance()
        {
            if (!instance) {
                instance = new Singleton;
            }

            return instance;
        }
        ~Singleton()
        {
            
        }
};

Singleton * Singleton::instance = nullptr;

int main()
{
    Singleton *s = Singleton::getInstance();

    std::cout << " value " << s->getVar() << std::endl;
    return 0;
}