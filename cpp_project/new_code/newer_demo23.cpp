#include <iostream>
#include <math.h>
#include<vector>
#include<string>
#include<map>
using namespace std;
bool isPrime(int n) {
    for (int i = 2; i < sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}


int main() {
    int n;
    cin >> n;
    vector<int> nums;

    map<int, int> m;
    m.end();
    int i = 2;
    while (!isPrime(n)) {
        if (isPrime(i) && n % i == 0) {
            nums.push_back(i);
            n /= i;
            continue;//即跳入下一次循环  不执行i++了
        }
        i++;
    }

    nums.push_back(n);

    for (int i : nums) {
        cout << i <<' ';

    }

    string s;
    s.rfind('\\');//逆向查找  从后往前找出字符"\\"  返回下标位置
    return 0;
}