#include "student.h"
// 无参构造函数的实现
Person::Person()
{
    name = NULL;
}

// 有参构造函数实现
Person::Person(char *na, char s, int a)
{
    if (na)
    {
        name = new char[strlen(na) + 1];
        strcpy(name, na);
    }
    sex = s;
    age = a;
}

Person::~Person()
{
    if (name)
    {
        delete[] name;
    }
}

// Student 类的函数实现

// 无参构造函数
Student::Student()
{
}

// 有参构造函数
Student::Student(char *na, char s, int a, char *spec, char *num) : Person(na, s, a) // 基类的构造函数不能被继承，在声明派生类时，对继承过来的成员变量的初始化工作也要由派生类的构造函数来完成
{
    strcpy(speciality, spec);
    strcpy(number, num);
}

Student::~Student() {}

// 重载赋值运算符的实现
Student &Student::operator=(Student &stu)
{
    strcpy(name, stu.name);
    sex = stu.sex;
    age = stu.age;
    strcpy(speciality, stu.speciality);
    strcpy(number, stu.number);
    return *this; // 返回当前Student的对象引用
}

// 重载转换类型运算符
Student::operator char *()
{
    return name;
}

Student::operator char()
{
    return sex;
}

Student::operator int()
{
    return age;
}

ostream &operator<<(ostream &out, const Student &stu)
{
    out << stu.name << '\t';
    out << stu.sex << '\t';
    out << stu.age << '\t';
    out << stu.number << '\t';
    out << stu.sex << '\t';
    return out;
}

istream &operator>>(istream &in, Student &stu)
{
    char temp[80];
    cout << "输入学生信息" << endl;
    cout << "姓名： ";
    in >> temp;
    if (temp)
    {
        stu.name = new char[strlen(temp) + 1];
        strcpy(stu.name, temp);
    }

    cout << "性别：";
    in >> stu.sex;
    cout << "年龄：";
    in >> stu.age;
    cout << "专业：";
    in >> stu.speciality;
    cout << "学号：";
    in >> stu.number;
    return in;
}