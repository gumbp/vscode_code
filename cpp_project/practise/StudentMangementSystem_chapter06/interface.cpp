#include "interface.h"
#include "student.h"
#include <iostream>

// 无参构造函数
Interface::Interface()
{
    num = 0;
}

void Display()
{
    // cout << "**********0.退   出**********" << endl;
    // cout << "**********1.录入信息**********" << endl;
    // cout << "**********2.查询信息**********" << endl;
    // cout << "**********3.浏览信息**********" << endl;
    // cout << "**********4.年龄排序**********" << endl;
    // cout << "**********5.统计信息**********" << endl;
    cout << "0.exit" << endl;
    cout << "1.input information" << endl;
    cout << "2.find the information" << endl;
    cout << "3.browse the information" << endl;
    cout << "4.counting the information by age" << endl;
    cout << "5.statistic the information" << endl;

    
}

void Interface::Run()
{
    int choice;
    do
    {
        cout << endl;
        Display();
        cout << "please input your choises" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0:
            break;
        case 1:
            Input();
            break;

        case 2:
            search();
            break;
        case 3:
            Browse();
            break;
        case 4:
            sort();
            break;

        case 5:
            Statistic();
            break;
        }
    } while (choice);
}

void Interface::Input()
{
    if (num == N)
    {
        // cout << "数据已满，不可录入" << endl;
    cout << "the data space is full,recording failed" << endl;
        return;
    }
    int i = num;
    cin >> st[i]; // 录入学生信息
    num++;
}

void Interface::Browse()
{
    // cout << "你要查看的学生数据如下" << endl;
    cout << "the information of the student who you want to check is following"<<endl;
    if (num == 0)
    {
        // cout << "没有数据" << endl;
        cout << "no data were found" << endl;
        return;
    }
    else
        cout << "姓名" << '\t' << "性别" << '\t' << "年龄" << '\t' << "专业" << '\t' << "学号" << '\n';
    for (int i = 0; i < num; i++)
    {
        cout << st[i];
    }
}

bool Interface::search()
{
    char na[20];
    int i = 0;
    cout << "你要查找的学生如下" << endl;
    cout << "请输入要查找的名字" << endl;
    cin >> na;
    for (i = 0; i < num; i++)
    {
        if (strcmp((char *)(st[i]), na) == 0)
        {
            break;
        }
    }
    if (i == num)
    {
        cout << "查无此人" << endl;
        return false;
    }
    cout << st[i]<<endl;
    return true;
}

void Interface::sort()
{
    cout << "按学生年龄排序" << endl;
    int k;

    // 选择法排序  记录每一趟中最大值的下标  第一层for循环控制比较趟数  第二层for循环用于找出每一趟最大值的下标
    for (int i = 0; i < num - 1; i++)
    {
        k = i;
        for (int j = i + 1; j < num; j++)
        {
            if ((int)(st[k]) < (int)(st[j]))
                k = j;
        }
        // 内层for循环每结束一次  此时k记录的是该趟找出的最大年龄的下标
        if (k != i)
        {
            Student t = st[k];
            st[k] = st[i];
            st[i] = t;
        }
    }
}

void Interface::Statistic()
{
    int m = 0;
    cout << "按性别统计人数" << endl;
    for (int i = 0; i < num; i++)
    {
        if (char(st[i]) == 'M' || char(st[i]) == 'm')
        {
            m++;
        }
        cout << "\n统计结果:男同学" << m << "人" << endl;
    }
}