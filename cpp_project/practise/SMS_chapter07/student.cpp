#include "student.h"
Student::Student()
{
    age = 0;
}

Student::Student(string na, string id, string num, string spec, int ag)
{
    name = na;
    ID = id;
    number = num;
    speciality = spec;
    age = ag;
}

Student::Student(const Student &per)
{
    name = per.name;
    age = per.age;
    speciality = per.speciality;
    ID = per.ID;
}

Student::~Student() {}

string Student::Getname()
{
    return name;
}

string Student::GetID()
{
    return ID;
}

string Student::GetNumber()
{
    return number;
}

int Student::GetAge()
{
    return age;
}

string Student::GetSpec()
{
    return speciality;
}

void Student::Display() const
{
    cout << "姓   名:" << name << endl;
    cout << "身份证号:" << ID << endl;
    cout << "学   号:" << number << endl;
    cout << "年   龄:" << age << endl;
    cout << "专   业:" << speciality << endl;
}

void Student::input()
{
    cin.get();
    cout << "输入姓名：";
    getline(cin, name);
    cin.get();
    cout << "输入身份证：";
    getline(cin, ID);

    cin.get();
    cout << "输入学号：";
    getline(cin, number);

    cin.get();
    cout << "输入专业：";
    getline(cin, speciality);

    cout << "输入年龄：";
    //cin.get();
    cin >> age;
}
