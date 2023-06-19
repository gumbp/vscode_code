#include<iostream>
#include<string>
using namespace std;
// int main(){
//     string subject("we love ");
//     string obj;
//     getline(cin, obj, ' ');
//     cout << subject << obj;
//     return 0;
// }


int main(){
    int n;
    string line;
    cin >> n; // 使用cin读入字符时，默认忽略前面的空格，但最终读取会留有‘\n’，作为下一个输入，显然此时getline读取的是‘\n’，若要更改此问题，可以加一个cin.get()，将该‘\n’读入，即可不影响getline的读取！
    cin.get();//此时读取的是第一个输入后面的的‘\n’
    getline(cin, line);
    cout << n <<endl<< line;
    return 0;
}