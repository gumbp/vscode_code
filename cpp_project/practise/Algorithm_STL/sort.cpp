#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int intarr[] = {1, 2, 35, 2, 3, 2, 23, 5, 7, 4, 3};
    vector<int> vec1(intarr, intarr + sizeof(intarr) / sizeof(int));
    // sort接受两个指向序列首尾的const类型的迭代器,并一升序排序序列
    vector<int>::iterator p = vec1.begin();
    while (p != vec1.end())
    {
        cout << *p++ << " ";
    }
    cout << endl;
    sort(vec1.begin(), vec1.end());
    p = vec1.begin();
    while (p != vec1.end())
    {
        cout << *p++ << " ";
    }
    cout << endl;
    return 0;
}