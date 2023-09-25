/*
 * @Author: Mr.Gan 
 * @Date: 2023-09-17 20:50:35 
 * @Last Modified by:   Mr.Gan 
 * @Last Modified time: 2023-09-17 20:50:35 
 */
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char rabbit[16] = {'p', 'e', 't', 't', 'r'};
    cout << "String length is " << strlen(rabbit) << endl;
    for (int i = 0; i < 16;i++)
    {
        cout << i
             << ":" << +rabbit[i] << "(" << rabbit[i] << ")" << endl;
    }
    return 0;
}
