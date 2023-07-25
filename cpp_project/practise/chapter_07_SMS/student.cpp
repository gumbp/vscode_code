#include "student.h"
Student::Student()
{
    age = 0;
}

Student::Student(string name, string ID, string number, string speciality, int age)
{
    this->ID = ID;
    this->name = name;
    this->number = number;
    this->speciality = speciality;
    this->age = age;
}

Student::Student(const Student &stu)
{
    ID = stu.ID;
    name = stu.name;
    number = stu.number;
    speciality = stu.speciality;
    age = stu.age;
}

Student::~Student()
{
}

int Student::get_age()
{
    return age;
}
string Student::get_ID()
{
    return ID;
}
string Student::get_name()
{
    return name;
}
string Student::get_number()
{
    return number;
}
string Student::get_speciality()
{
    return speciality;
}

void Student::display() const
{
    cout << "姓   名:" << name << endl;
    cout << "身份证号:" << ID << endl;
    cout << "学    号:" << number << endl;
    cout << "专    业:" << speciality << endl;
    cout << "年    龄:" << age << endl;
}

void Student::input()
{
    cin.get();
    cout << "请输入名字" << endl;
    getline(cin, name);
    cin.get();
    cout << "请输入身份证号" << endl;
    getline(cin, ID);
    cin.get();
    cout << "请输入学号" << endl;
    getline(cin, number);
    cin.get();
    cout << "请输入专业" << endl;
    getline(cin, speciality);
    cin.get();
    cout << "请输入年龄" << endl;
    cin.get();
    cin >> age;
}
