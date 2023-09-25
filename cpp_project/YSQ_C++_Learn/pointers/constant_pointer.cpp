/*
 * @Author: Mr.Gan
 * @Date: 2023-09-18 11:01:16
 * @Last Modified by: Mr.Gan
 * @Last Modified time: 2023-09-18 13:12:07
 */
#include <iostream>
using namespace std;
int main()
{
    int num = 1;
    int another = 2;
    const int *p = &num;       // 指向常量的指针
    int *const q = &num;       // 常指针
    const int *const r = &num; // 指向常量的常指针

    // *p = 2; // error 指向常量的指针不允许修改指向的变量的值
    p = &another;//right 指向常量的指针允许修改指向的变量
    *q = 3;//right 常指针允许修改指向的地址的内存值
    // q = &another;//error  常指针不允许修改指向的内存地址

    //error 指向常量的常指针不允许修改地址和地址里的值
    // r = &another;
    // *r = 2;
}