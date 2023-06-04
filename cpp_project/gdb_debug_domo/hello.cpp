#include <iostream>
using namespace std;
double feibonaqie(double n)
{
    if (n <= 0)
    {
        cout << "please input the right paramater" << endl;
        return 0;
    }

    else if (n <= 2)
    {
        return 1;
    }
    else
    {
        return feibonaqie(n - 1) + feibonaqie(n - 2);
    }
}

double calculate_n(double n)
{
    if (n < 1)
    {
        cout << "error parameter,please input again" << endl;
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return calculate_n(n - 1) * n;
    }
}

int main()
{
    double n;
    cout << "please input n" << endl;
    cin >> n;
    cout << "该项斐波那契值为" << feibonaqie(n) << endl;
    cout << n << "的阶乘为" << calculate_n(n) << endl;
    return 0;
}
