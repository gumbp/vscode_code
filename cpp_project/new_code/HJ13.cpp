#include <iostream>
#include <string>
#include<stack>
using namespace std;

int main() {
    string s;
    stack<string> st;
    while (cin >> s) {//cin逐个读取单词  遇到空格停止   随后将单词进栈
        st.push(s);
    }
    while (!st.empty()) {
        cout << st.top()<<" ";
        st.pop();
    }
    return 0;
}