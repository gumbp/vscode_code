#ifndef POINT_H //如果没有定义POINT_H这个宏，则编译以下代码
#define POINT_H 0 //

#include <iostream>
using namespace std;
class Point
{
private:
    int x;
    int y;

public:
    Point();
    Point(int a, int b = 0);
    void print();
    Point operator+(Point p1); // 返回类型为point  函数名为opreator+
    friend Point operator-(Point p1, Point p2);
};

#endif