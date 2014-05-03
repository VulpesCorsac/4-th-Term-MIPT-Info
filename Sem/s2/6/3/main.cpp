#include <iostream>

template <typename T>
T sum(T x, T y);

template <typename T>
T sum(T x, T y)
{
    return x + y;
}

int main()
{
    int x = 1, y = 5;
    std::cout << sum(x, y) << "\n";
    
    float a = 2.7, b = 7.9;
    std::cout << sum(a, b) << "\n";
}