#include <iostream>
#include "3_lib.h"

int main(int argc, char *argv[])
{
    Math::Complex a(2.0, 5.0), b(8.0, -1.0), c;
    c = 5;
    std::cout << c.getReal() << " + " << c.getImg() << "i\n";
    return 0;
}