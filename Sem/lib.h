#include <iostream>

class Class1
{
    int x, y;
public:
    Class1(int x, int y);
    void show();
};

class Class2
{
    float x, y;
public:
    Class2(float x, float y);
    void show();
};

Class1::Class1(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Class1::show()
{
    std::cout << this->x << " " << this->y << "\n";
}

Class2::Class2(float x, float y)
{
    this->x = x;
    this->y = y;
}

void Class2::show()
{
    std::cout << this->x << " " << this->y << "\n";
}