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
    cout << "��   ��:" << name << endl;
    cout << "���֤��:" << ID << endl;
    cout << "ѧ    ��:" << number << endl;
    cout << "ר    ҵ:" << speciality << endl;
    cout << "��    ��:" << age << endl;
}

void Student::input()
{
    cin.get();
    cout << "����������" << endl;
    getline(cin, name);
    cin.get();
    cout << "���������֤��" << endl;
    getline(cin, ID);
    cin.get();
    cout << "������ѧ��" << endl;
    getline(cin, number);
    cin.get();
    cout << "������רҵ" << endl;
    getline(cin, speciality);
    cin.get();
    cout << "����������" << endl;
    cin.get();
    cin >> age;
}
