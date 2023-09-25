// 在C和C++语言中，volatile是一个关键字，用于告诉编译器该变量可能会被意外地修改，因此编译器不应该对该变量进行优化。它通常用于以下情况：
// 多线程环境：当多个线程同时访问同一个变量时，volatile关键字可以确保每个线程都能正确地读取和写入该变量的最新值，而不会使用缓存或寄存器中的旧值。
// 中断处理程序：在嵌入式系统中，中断处理程序可能会修改某些全局变量。使用volatile关键字可以确保编译器不会对这些变量进行优化，以避免出现意外的行为。

// 访问硬件寄存器：在与硬件交互的程序中，volatile关键字可以确保对硬件寄存器的读写操作不会被编译器优化掉。
#include <stdio.h>
int counter = 0;
// volatile int counter = 0;
void incrementCounter() {
    counter++;
}

int main() {
    printf("Counter: %d\n", counter);  // 输出初始值

    incrementCounter();  // 修改counter的值

    printf("Counter: %d", counter);  // 输出修改后的值

    return 0;
}