#include <iostream>
#include <math.h>
#include <stdio.h>
#include <cstdlib>

double erand48(unsigned short xsubi[3])
{
    return double(rand()) / double(RAND_MAX);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
