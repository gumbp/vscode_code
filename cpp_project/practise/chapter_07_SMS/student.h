#ifndef _STUDENT
#define _STUDENT
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define SIZE 80
class Student
{
    string name;
    string ID;
    string number;
    string speciality;
    int age;

public:
    Student();                  
    Student(string name, string ID, string number, string speciality, int age);
    Student(const Student &stu);
    ~Student();
    string get_name();
    string get_ID();
    string get_number();
    string get_speciality();
    int get_age();
    bool insert();
    void display() const;
    void input();
};

#endif