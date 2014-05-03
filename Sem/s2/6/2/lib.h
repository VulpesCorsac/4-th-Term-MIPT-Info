template <typename Type> class MyClass
{
    Type x, y;
    
public:
    MyClass();
    MyClass(Type x, Type y);
    Type getSum();
};

template <typename Type>
MyClass<Type>::MyClass()
{
    MyClass(0, 0);
}
    
template <typename Type>
MyClass<Type>::MyClass(Type x, Type y)
{
    this->x = x;
    this->y = y;
}
            
template <typename Type>
Type MyClass<Type>::getSum()
{
    return x + y;
}