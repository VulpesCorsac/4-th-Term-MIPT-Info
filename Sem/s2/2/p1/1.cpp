#include <iostream>
#include "1_lib.h"

int main(int argc, char *argv[])
{
    Math::Complex a(2.0, 5.0), b(8.0, -1.0), c;
    c.add(a, b);
    std::cout << c.getReal() << " + " << c.getImg() << "i\n";
    return 0;
}