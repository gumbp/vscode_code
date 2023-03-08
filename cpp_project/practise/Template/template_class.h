#include <iostream>
using namespace std;
template <class T1, class T2>
class Myclass
{
public:
    Myclass(T1 xx, T2 yy);
    void Print();

private:
    T1 x;
    T2 y;
};

template <class T1, class T2>
Myclass<T1, T2>::Myclass(T1 x, T2 y)
{
    this->x = x;
    this->y = y;
}

template <class T1, class T2>
void Myclass<T1, T2>::Print()
{
    cout << "x=" << x<<" y=" << y << endl;
}

