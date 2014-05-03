#include <iostream>

class Range_error
{
    int i;
public:
    Range_error(int ii)
    {
        i = ii;
    }
    int get_i()
    {
        return i;
    }
};

char toChar(int i)
{
    if (i < std::numeric_limits<char>::min() || std::numeric_limits<char>::max() < i)
        throw Range_error(i);
    return i;
}

int main()
{
    try
    {
        char c = toChar(1000);
        std::cout << c << "\n";
    }
    catch (Range_error x)
    {
        std::cerr << "Error: toChar(" << x.get_i() << ")\n";
    }
}