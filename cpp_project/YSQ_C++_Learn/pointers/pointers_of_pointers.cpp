/*
 * @Author: Mr.Gan
 * @Date: 2023-09-18 10:43:01
 * @Last Modified by: Mr.Gan
 * @Last Modified time: 2023-09-19 16:36:13
 */
#include <iostream>
using namespace std;
int main()
{
    int num = 10;
    int *p = &num;
    int **q = &p;
    cout << "the num's value is:" << num << endl;
    cout << "the p's value is" << *p << endl;
    cout << "the num's address is :" << p << endl;
    cout << "the pointer p's adress is:" << q << endl;
    cout << "the bytes of the p are:" << sizeof(p) << endl;
    cout << "the bytes of the q are:" << sizeof(q) << endl;
    return 0;
