#include<iostream>
#include<string>
using namespace std;
//字符串初始化举例
int main(){
    const char text[] = "hello world";
    string s1 = text; //用其他字符串来初始化string对象
    string s2(s1);//拷贝构造函数
    string s3(&text[0], &text[5]);//即s3为hello
    string s4(10, '0');//用一个0序列初始化s4
    //string s5(s2.begin(), s2.find(' '));
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
  //  cout << s5 << endl;


  //string中的IO类   cin只能读取连续字符  遇到空白字符停止读取
    string s6, s7;
    cin >> s6;
    cin >> s7;
    cout << s6<<endl;
    cout << s7;

//若要将整行输入进行读取   则可考虑使用getline函数
    string obj;
    getline(cin, obj, '.');
    cout << obj << endl;





    return 0;
}
