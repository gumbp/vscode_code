#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define SIZE 10


int main()
{
    vector<int> array = {1, 2, 34, 60, 50, 50, 67, 67, 89};
    // 找到容器中值为50的下标
    vector<int>::iterator ip = find(array.begin(), array.end(), 50);
    if (ip == (array.end()++))
    {
        cout << "50不在数组列表中" << endl;
    }
    else
        cout << *ip << "  found in the array" << endl;

    // 找到相邻值相等的第一个元素
    ip = adjacent_find(array.begin(), array.end());
    cout << *ip << endl;


    //count the numbers which value is 50
    cout<<count(array.begin(), array.end(), 50);
    return 0;
}