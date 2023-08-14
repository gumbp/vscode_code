#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>&nums,int low, int high){
    int pivot=low;
    while(low<high){
        while(low<high&&nums[high]>=nums[pivot]){
            high--;
        }
        nums[low] = nums[pivot];
        while(low<=high&&nums[low]<=nums[pivot]){
            low++;
        }

        nums[high] = nums[low];
    }
    return low;
}


void quicksort(vector<int>nums,int low, int high){
    if(low<high){
        int pivotpos = partition(nums, low, high);
        quicksort(nums, low, pivotpos - 1);
        quicksort(nums, pivotpos + 1, high);
    }
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void select_sort(vector<int>nums){
    for (int i = 0; i < nums.size() - 1;i++){
        int min = i;
        for (int j = i + 1; j < nums.size();j++){
            if(nums[j]<nums[min]){
                min = j;
            }
        }
        if(min!=i){
            swap(nums[min], nums[i]);
        }
    }

}


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