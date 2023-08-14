#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
int main(){
    int intarr_1[]={1,2,4,2,3,5,6,6,7,7,7,6,8,9,8};
    vector<int> vec_1(intarr_1, intarr_1+ sizeof(intarr_1) / sizeof(int));
    int intarr_2[] = {1,3,2,3,4,5,7,7,9,7};
    vector<int> vec_2(intarr_2, intarr_2 + sizeof(intarr_2) / sizeof(int));
    vector<int>::iterator ip;
    // 找到相邻两个元素相等的第一个元素
    ip = adjacent_find(vec_1.begin(), vec_1.end());
    cout << *ip << endl;
    // 统计vec_1中元素值为7的元素个数
    cout << count(vec_1.begin(), vec_1.end(), 7)<<endl;
    //找到vec_1中元素中小于7的元素个数
    cout << count_if(vec_1.begin(), vec_1.end(), bind2nd(less<int>(),7))<<endl;
    // 判断两个容器值是否相等 0假1真
    cout << equal(vec_1.begin(),vec_1.end(), vec_2.begin());
    return 0;
}
