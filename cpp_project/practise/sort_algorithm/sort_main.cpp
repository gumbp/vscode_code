#include "sort.h"
int main()
{

    sort_compare mysort(10);
    mysort.run(mysort.GetNums());
    return 0;
}