template <typename T, int length>
class Array
{
    T n[length];

public:
    Array();
    void set_n(int i, T x);
    int get_length();
    T get_n(int i);
};

template <typename T, int length>
Array<T, length>::Array()
{
    
}

template <typename T, int length>
void Array<T, length>::set_n(int i, T x)
{
    this->n[i] = x;
}

template <typename T, int length>
int Array<T, length>::get_length()
{
    return length;
}

template <typename T, int length>
T Array<T, length>::get_n(int i)
{
    return this->n[i];
}