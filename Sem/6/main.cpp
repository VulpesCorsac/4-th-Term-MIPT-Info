#include "lib.h"
#include <iostream>

int main()
{
    Array<int, 2> X;
    X.set_n(0, 1);
    X.set_n(1, 2);
    std::cout << X.get_length() << "\n";
    std::cout << X.get_n(0) << "\n";
    std::cout << X.get_n(1) << "\n";
    return 0;
}