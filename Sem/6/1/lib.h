class Class1
{
    int x, y;
    
public:
    Class1();
    Class1(int x, int y);
    int getSum();
};

class Class2
{
    float x, y;

public:
    Class2();
    Class2(float x, float y);
    float getSum();
};

Class1::Class1()
{
    Class1(0, 0);
}
    
Class1::Class1(int x, int y)
{
    this->x = x;
    this->y = y;
}
            
int Class1::getSum()
{
    return x + y;
}
                
Class2::Class2()
{
    Class2(0, 0);
}
                    
Class2::Class2(float x, float y)
{
    this->x = x;
    this->y = y;
}
                            
float Class2::getSum()
{
    return x + y;
}