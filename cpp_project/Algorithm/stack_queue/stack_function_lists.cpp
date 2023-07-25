#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 判断字符串是否为回文  算法思路：借助栈这数据结构，将前半段数据入栈，之后依次出栈，与后续元素比较  时间复杂度为O（n） 空间复杂度为O（n） （栈的应用）
bool isPalindrome(string &str)
{
    stack<char> s;
    int len = str.size();
    int i = 0;
    for (; i < len / 2; i++)
    {
        s.push(str[i]);
    }
    if (len % 2 != 0)
    {
        i++;
    }
    while (!s.empty())
    {
        char temp = s.top();
        s.pop();
        if (temp != str[i])
        {
            return false;
        }
        else
        {
            i++;
        }
    }
    return true;
}
//常规做法
bool ishuiwen(string &str){
    int i=0;
    int j = str.size() - 1;
    while(i<=j){
        if(str[i]==str[j]){
            i--;
            j++;
        }
        else{
            return false;
        }
    
    }
    return true;

}

int main()
{
    string s;
    cin >> s;
    if (isPalindrome(s))
    {
        cout << "字符串" << s << "为回文" << endl;
    }
    else
    {
        cout << "字符串" << s << "不为回文" << endl;
    }
    return 0;
}