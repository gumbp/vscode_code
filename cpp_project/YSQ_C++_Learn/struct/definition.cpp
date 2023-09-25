#include <iostream>
#include <string>
using namespace std;

// c++的结构体中无需添加typedef
struct Student
{
    char name[4];
    int born;
    bool male;
};

int main()
{
    Student stu = {"gan", 2000, true};
    cout << stu.name << " " << stu.born << " " << (stu.male ?"male":"female")<< endl;
    Student *stu_point = &stu;
    cout << stu_point->name << " " << stu_point->born << " " << (stu_point->male ? "male" : "female");
    return 0;
}