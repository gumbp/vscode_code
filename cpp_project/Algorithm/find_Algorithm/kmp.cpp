#include <iostream>
#include <vector>
using namespace std;
#define N 100

// 定义串的数据结构
typedef struct
{
    char ch[N];
    int length;
} SString;

void get_next(SString &T, int next[])
{
    int i = 1, j = 0;
    next[1] = 0;
    while (i < T.length)
    {
        if (j == 0 || T.ch[i] == T.ch[j])
        {
            ++i, ++j;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}

int Index_KMP(SString &s, SString &t)
{
    int i = 1, j = 1;
    int next[N];
    get_next(t, next);
    while (i <= s.length && j <= t.length)
    {

        // 若相等则继续比较下一字符
        if (j == 0 || s.ch[i - 1] == t.ch[j - 1])
        {
            ++i;
            ++j;
        }

        // 否则模式串的下一比较字符为t.ch[next[j]]
        else
        {
            j = next[j];
        }
    }
    if (j > t.length)
    {
        cout << "匹配成功" << endl;
        cout << "在" << i - t.length << "处匹配成功" << endl;
        return 0;
    }
    else
    {
        cout << "匹配失败" << endl;
        return 0;
    }

}

// 重载输入流 便于特定输入
//  void operator>>(istream &in, SString &a)
istream &operator>>(istream &in, SString &a)
{
    cout << "please input the length of the string" << endl;
    cin >> a.length;
    cout << "please input the  string " << endl;
    for (int i = 0; i < a.length; i++)
    {
        cin >> a.ch[i];
    }
    return in;
}


int main()
{
    SString s, t;
    cout << "输入主串" << endl;
    cin >> s;
    cout << "输入模式串" << endl;
    cin >> t;

    Index_KMP(s, t);
    return 0;
}
