/**
 * Written by Devendra Naga (devendra.aaru@gmail.com)
 * 
 * License Apache
 */
#include <iostream>
#include <chrono>

class deltaClass {
    private:
        std::chrono::time_point<std::chrono::steady_clock> start;
        std::chrono::time_point<std::chrono::steady_clock> end;
    public:
        deltaClass()
        {

        }

        void startTiming();
        void stopTiming();
        double getTimeDelta();
};

void deltaClass::startTiming()
{
    start = std::chrono::steady_clock::now();
}

void deltaClass::stopTiming()
{
    end = std::chrono::steady_clock::now();
}

double deltaClass::getTimeDelta()
{
    std::chrono::duration<double> delta = end - start;

    return delta.count();
}

int main()
{
    int i;
    deltaClass timer;

    timer.startTiming();

    for (i = 0; i < 9000000; i ++) {
    }

    timer.stopTiming();

    double delta = timer.getTimeDelta();

    std::cout << "delta " << delta << std::endl;
}
