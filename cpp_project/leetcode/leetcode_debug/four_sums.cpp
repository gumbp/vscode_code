#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> fourSum(vector<int> &nums, long long target)
{
    if (nums.size() < 4)
    {
        return {};
    }

    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int i = 0;
    while (i < static_cast<int>(nums.size() - 3))
    {
        if (nums[i] > target && nums[i] >= 0)
        {
            return res;
        }
        int j = i + 1;
        while (j < static_cast<int>(nums.size() - 2))
        {

            if (nums[i] + nums[j] > target && nums[i] >= 0)
            {
                return res;
            }
            long long temp = target - (nums[i] + nums[j]);
            int k = j + 1;
            int l = nums.size() - 1;
            while (k < l)
            {
                if (nums[k] + nums[l] == temp)
                {
                    res.push_back({nums[i], nums[j], nums[k], nums[l]});
                    while (k < l && nums[k] == nums[k + 1])
                        k++;
                    while (k < l && nums[l] == nums[l - 1])
                        l--;
                    k++;
                    l--;
                }
                else if (nums[k] + nums[l] < temp)
                {
                    k++;
                }
                else
                {
                    l--;
                }
            }
            // 对第二个元素降重  防止重复结果
            while (j < static_cast<int>(nums.size() - 2) && nums[j] == nums[j + 1])
                j++;
            j++;
        }
        // 对第一个元素降重  防止重复结果
        while (i < static_cast<int>((nums.size() - 3)) && nums[i] == nums[i + 1])
            i++;
        i++;
    }
    return res;
}

ostream &operator<<(ostream &os, vector<int> a)
{
    for (auto it : a)
    {
        os << it << " ";
    }
    return os;
}

int main()
{
    vector<int> nums = {-1000000000,-1000000000,-1000000000,-1000000000,-1000000000};
    int target = 294967296;
    vector<vector<int>> res = fourSum(nums, target);
    if(res.size()<=0){
        cout << "the result array is null" << endl;
        return 0;
    }
    for (const auto &it : res)
    {
        cout << it << endl;
    }
    return 0;
}