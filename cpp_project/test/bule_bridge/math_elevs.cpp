#include <iostream>
using namespace std;

int main() {
    // 定义起始数字和结束数字
    size_t a = 1;
    size_t b = 2024041331404202;
    size_t count = 0; // 统计满足条件的数字个数
    
    // 观察：当 i >= 100 时，B(i) 一定能被100整除，因为 B(i) = i! 包含因子 100
    // 当 B(i) % 100 == 0 时，要使 (A(i) - B(i)) % 100 == 0，只需要 A(i) % 100 == 0
    
    // 处理 i < 100 的情况，需要逐个计算 A(i) 和 B(i)
    for (size_t i = a; i < 100; i++) {
        // 计算 A(i)，即 1+2+...+i = i*(i+1)/2
        size_t A = i * (i + 1) / 2;
        
        // 计算 B(i)，即 1*2*...*i = i!
        size_t B = 1;
        for (size_t j = 1; j <= i; j++) {
            B *= j;
            // 只关心 B 对 100 取模的结果，避免溢出
            B %= 10000; // 取模一个较大的值以保留更多信息
        }
        
        // 检查 A(i) - B(i) 是否能被 100 整除
        if ((A - B) % 100 == 0) {
            count++;
        }
    }
    
    // 处理 i >= 100 的情况
    // 当 i >= 100 时，B(i) 必然包含因子 100（因为 B(i) 包含 4*5*5*...）
    // 所以当 i >= 100 时，(A(i) - B(i)) % 100 = (A(i) - 0) % 100 = A(i) % 100
    
    // 当 i >= 100 时：
    // i = 100, 101, ..., b
    // 这些数字都满足条件
    if (b >= 100) {
        count += (b - 100 + 1);
    }
    
    // 输出结果
    cout << count << endl;
    
    return 0;
}