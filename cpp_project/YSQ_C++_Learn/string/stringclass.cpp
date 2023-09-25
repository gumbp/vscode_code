/*
 * @Author: Mr.Gan 
 * @Date: 2023-09-17 20:53:26 
 * @Last Modified by: Mr.Gan
 * @Last Modified time: 2023-09-17 20:59:59
 */
#include<iostream>
#include<string>
using namespace std;
int main(){
    string str="guangxi  university";
    cout<<str[100]<<endl;//越界  但是 不报错 而是访问了其他内存空间
    cout << str.at(1);
    return 0;
}