/*
 * @Author: Mr.Gan 
 * @Date: 2023-09-18 12:44:30 
 * @Last Modified by: Mr.Gan
 * @Last Modified time: 2023-09-18 13:12:25
*/
#include<iostream>
using namespace std;
int main(){
    int *p1 = new int;//未初始化
    int *p2 = new int();//初始化为0
    int *p3 = new int(5);//初始化为5
    int *p4 = new int{};//c++11  初始化为0
    int *p5 = new int{5};//初始化为5 c++11标准
    return 0;
}