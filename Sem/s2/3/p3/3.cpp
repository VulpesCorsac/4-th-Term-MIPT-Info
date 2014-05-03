#include <iostream>
#include "3_lib.h"

int main(int argc, char *argv[])
{
    Math::Complex a(2.0, 5.0), b(1.7, 4.7), c;
    c = a+b;
    std::cout << c << "\n";
    
    Math::Matrix22 A(2,5,4,-9);
    Math::Vector2 x(4, -7), y;
    
    y = A*x;
    
    std::cout << y.getX() << ", " << y.getY() << "\n";
    return 0;
}