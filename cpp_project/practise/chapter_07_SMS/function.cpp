#include "function.h"
#include "student.h"
static int count11 = 0;
void menu()
{
    cout << "1.录入信息" << endl;
    cout << "2.查询信息" << endl;
    cout << "3.浏览信息" << endl;
    cout << "0.退    出" << endl;

}


void OutptuStu(vector<Student> &stu_vec){
    
    vector<Student>::const_iterator p;
    for (p = stu_vec.begin(); p != stu_vec.end();p++){
        (*p).display();
        cout << endl;
    }
    cout << "学生总人数为" << count11<<endl;
}
void InputStu(vector<Student> &stu_vec){
    char ch;
    Student x;
    do{
        x.input();
        count11++;
        stu_vec.push_back(x);
        cout << "继续输入吗（Y/N）" << endl;
        cin.get();
        cin.get(ch);

    } while (ch=='Y'||ch=='y');
}


void find_student(vector<Student> &stu_vec,string &name){
    cout << "请输入要查找学生的姓名" << endl;
    cin.get();
    getline(cin, name);
    vector<Student>::iterator p;
    for (p = stu_vec.begin(); p != stu_vec.end();p++){
        if((*p).get_name().compare(name)==0){
            (*p).display();
            break;
        }
    }
    if(p==stu_vec.end()){
        cout << "查无此人" << endl;

    }
}


void run(){
    vector<Student> stu_vec;
    string name;
    int choice;
    do{
        menu();
        cout << "请输入你的选择" << endl;
        cin >> choice;
        if(choice<0||choice>3){
            cout << "输入有误，请重新输入" << endl;
            break;
        }
        else{
            switch (choice)
            {
            case 1:
                InputStu(stu_vec);
                break;
            case 2:
                find_student(stu_vec, name);
                break;
            case 3:
                OutptuStu(stu_vec);
                break;
            default:
                break;
            }
        }
    } while (choice);
}