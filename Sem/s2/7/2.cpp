#include <iostream>

struct Zero_devide {};

float devide(float a, float b)
{
    if (b == 0)
        throw Zero_devide();
    return a/b;
}

int main()
{
    float x = 5, y = 0;
    try
    {
        std::cout << devide(x, y) << "\n";
    }
    catch (Zero_devide)
    {
        std::cerr << "Devide by zero\n";
    }
    std::cout << "Something after exception processing\n";
    return 0;
}