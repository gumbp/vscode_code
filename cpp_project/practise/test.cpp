#include <iostream>

int main() {
    int count = 0;
    for (int i = 1; i <= 202504; ++i) {
        int sum = 0;
        int temp = i;
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        if (sum % 5 == 0) {
            count++;
        }
    }
    std::cout << count << std::endl;
    return 0;
}
