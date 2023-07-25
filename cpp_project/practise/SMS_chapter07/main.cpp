#include "student.h"
#include <algorithm>
#include <vector>
using namespace std;
void menu();
void OutputStu(vector<Student> &stu_vec);
void InputStu(vector<Student> &stu_vec);
void Find(vector<Student> &stu_vec,string &na);
int main()
{
    string a;
    cout << "输入字符" << endl;
    cin >> a;
    cout << a;

    vector<Student> stu_vec;
    int choice;
    string na;
    do
    {
        menu();
        cout << "please input your choice" << endl;
        cin >> choice;
        if (choice >= 0 && choice <= 3)
        {
            switch (choice)
            {
            case 1:
                InputStu(stu_vec);
                break;

            case 2:
                Find(stu_vec,na);
                break;

            case 3:
                OutputStu(stu_vec);
                break;
            default:
                break;
            }
        }
    } while (choice);

    return 0;
}

void menu()
{
    cout << "***********1.录入信息***********" << endl;
    cout << "***********2.查询信息***********" << endl;
    cout << "***********3.浏览信息***********" << endl;
    cout << "***********0.退    出***********" << endl;
}

void Find(vector<Student> &stu_vec,string &na)
{
    cout << "input the name search" << endl;
    cin.get();
    getline(cin, na);
    cin.get();
    vector<Student>::iterator p;
    for (p = stu_vec.begin(); p != stu_vec.end(); p++)
    {
        if ((*p).Getname().compare(na) == 0)
        {
            (*p).Display();
            break;
        }
    }

    if (p == stu_vec.end())
    {
        cout << "查无此人" << endl;
    }
}

void InputStu(vector<Student> &stu_vec)
{
    char ch;
    Student x;
    do
    {
        x.input();
        stu_vec.push_back(x);
        cout << "是否继续输入？  Y/N" << endl;
        cin.get(); // 此处是为了读取掉上一行cout剩余的‘\n’
        cin.get(ch);
    } while (ch == 'Y' || ch == 'y');
}

void OutputStu(vector<Student> &stu_vec)
{
    int count = 0;
    vector<Student>::const_iterator p;
    for (p = stu_vec.begin(); p != stu_vec.end(); p++)
    {
        (*p).Display();
        count++;
    }

    cout << "The Number of the Student are" << count << endl;
}