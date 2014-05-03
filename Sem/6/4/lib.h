template <typename T, int size>
class Class
{
    T a[size];

public:
    Class();
    void set_n(int n, T x);
    T get_n(int n);
    int get_size();
};

template <typename T, int size>
Class<T, size>::Class()
{
}

template <typename T, int size>
int Class<T, size>::get_size()
{
    return size;
}

template <typename T, int size>
void Class<T, size>::set_n(int n, T x)
{
    this->a[n] = x;
}

template <typename T, int size>
T Class<T, size>::get_n(int n)
{
    return this->a[n];
}