#include "demo_head.h"
int main(){
    Point p1(5, 10), p2(20, 30), p3, p4;
    p3 = p2 + p1;//相当于p1.operator+(p2)
    p4 = p1 - p2;//相当于p1.oprator-(p2)
    cout << "P1=";
    p1.print();
    cout << "p2=";
    p2.print();



    cout << "P1+P2=";
    p3.print();
    cout << "P1-P2=";
    p4.print();
    return 0;
}