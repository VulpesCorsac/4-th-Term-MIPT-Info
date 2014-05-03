#include <iostream>
#include "lib.h"

int main()
{
    Class<int, 2> a;
    a.set_n(0, 5);
    a.set_n(1, 9);
    std::cout << a.get_size() << " " << a.get_n(0) << " " << a.get_n(1) << "\n";
    return 0;
}