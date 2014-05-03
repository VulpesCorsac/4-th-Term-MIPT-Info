#include "lib.h"
#include <iostream>

int main()
{
    Class1 a(2, 6);
    Class2 b(5.8, 4.1);
    
    std::cout << a.getSum() << " " << b.getSum() << "\n";
}