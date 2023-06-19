#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    // string的几种初始化方式
    const char text[] = "hello world";
    string s1=text;
    string s2(s1);
    string s3(&text[0], &text[5]);//text中的部分字符  s3为hello
    string s4(10, '0');//用0来初始化s4
    // string s5 (s2.begin(),s2.find(' '));
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    // cout << s5 << endl;
    return 0;
}