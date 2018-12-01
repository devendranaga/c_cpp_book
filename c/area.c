#include <stdio.h>
#include <math.h>

double area_circle(double radius)
{
    return 2 * M_PI * radius * radius;
}

int main()
{
    printf("area of a circle %f\n", area_circle(4.5));
}

