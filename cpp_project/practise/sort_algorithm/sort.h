#ifndef sort_h
#define sort_h

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class sort_compare
{
private:
     vector<int> nums;

public:
    sort_compare();
    sort_compare(const int &n);
    sort_compare(const sort_compare &S);
    ~sort_compare();
    void menu();
    vector<int> GetNums();
    void Display();
    void run(vector<int>&nums);

    int partition(vector<int> &nums, int low, int high);

    vector<int> quick_sort(vector<int> &nums, int low, int high);
    
    void swap(int &x, int &y);

    vector<int> bubble_sort(vector<int> &nums);

    vector<int> insert_sort(vector<int> &nums);
    vector<int> sort_compare::select_sort(vector<int> &nums);
    vector<int> merge_sort(vector<int> &nums, int low, int high);
    void merge(vector<int> &nums, int low, int mid, int high);

    vector<int> count_sort(vector<int> &nums);

    vector<int> heap_sort(vector<int> &nums);
    void heap_adjustment(vector<int> &nums, int i, int n);

    // 查找算法

    int middle_search(vector<int> &nums, int key);
};

#endif