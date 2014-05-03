#include "lib.h"
#include <iostream>

int main()
{
    MyClass<int> a(2, 6);
    MyClass<float> b(5.8, 4.1);
    
    std::cout << a.getSum() << " " << b.getSum() << "\n";
}