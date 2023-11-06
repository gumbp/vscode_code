#include <iostream>
using namespace std;
int main()
{
    int n;
    int result = 1;
    cin >> n;
    while (n > 1)
    {
        result *= n;
        n--;
    }
    cout << result;
    return 0;
}