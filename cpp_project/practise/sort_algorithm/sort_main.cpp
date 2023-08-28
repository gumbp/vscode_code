#include "sort.h"
int main()
{

    sort_compare mysort(10);
    vector<int> arary=mysort.GetNums();
    mysort.run(arary);
    return 0;
}