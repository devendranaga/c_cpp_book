#include <iostream>
#include <memory>

int main()
{
    std::unique_ptr<double[]> s = std::make_unique<double[]>(5);
    double *d = s.get();

    for (int i = 0; i < 5; i ++) {
        d[i] = i;
    }

    for (int i = 0; i < 5; i ++)
        std::cout << d[i] << std::endl;
}

