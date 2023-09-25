/*
 * @Author: Mr.Gan 
 * @Date: 2023-09-18 12:37:19 
 * @Last Modified by: Mr.Gan
 * @Last Modified time: 2023-09-18 12:39:46
 */
#include<iostream>
using namespace std;
int main(){
    int *p=(int *)malloc(8*sizeof(int));
    free(p);
    for(int i=0;i<1024;i++)
    {
        p=(int *)malloc(1024*1024*1024);
    }
    cout<<"end";
    return 0;

}