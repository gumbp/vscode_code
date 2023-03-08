#include "student.h"
const int N = 2;
class Interface
{
protected:
    Student st[N];
    int num;

public:
    Interface();      // 学生信息系统界面
    void Browse();    // 浏览界面
    void Run();       // 系统启动
    void Input();     // 输入学生信息
    void sort();      // 按年龄排序学生信息
    void Statistic(); // 按性别统计学生信息
    bool search();    // 按名字查询学生信息
};
