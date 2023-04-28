#ifndef  sort_h
#define sort_h

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class sort
{
private:
    vector<int> nums;

public:
    sort();
    sort(const int &n);
    sort(const sort &S);
    ~sort();
    void menu();
    void Display();

    int partition(vector<int> &nums, int low, int high);
    vector<int> quick_sort(vector<int> &nums, int low, int high);
    void swap(int &x, int &y);

    vector<int> bubble_sort(vector<int> &nums);

    vector<int> select_sort(vector<int> &nums);

    vector<int> insert_sort(vector<int> &nums);

    vector<int> merge_sort(vector<int> &nums, int low, int high);
    void merge(vector<int> &nums, int low, int mid, int high);

    vector<int> count_sort(vector<int> &nums);

    vector<int> heap_sort(vector<int> &nums);
    void heap_adjustment(vector<int> &nums, int i, int n);

    // 查找算法
    int middle_search(vector<int> &nums, int key);
};

#endif