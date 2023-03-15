#ifndef _STUDENT
#define _STUDENT
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define SIZE 10
class Student
{
    string name;
    string ID;
    string speciality;
    string number;
    int age;

public:
    Student();
    Student(string na, string id, string num, string spec, int ag);
    Student(const Student &per);
    ~Student();
    string Getname();
    string GetID();
    string GetNumber();
    int GetAge();
    string GetSpec();
    void Display() const; // 定义为常成员函数
    void input();
};
#endif