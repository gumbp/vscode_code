#include<iostream>
#include <unistd.h>
int main()
{
    write(1,"hello world\n",12);
    printf("%d+%d=%d\n", 1, 1, 1 + 1);
    return 0;
}
