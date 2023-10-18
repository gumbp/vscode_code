/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
// @lc code=start
#include <deque>
#include <vector>
using namespace std;

// 暴力算法  超时
// class Solution
// {
// public:
// vector<int> maxSlidingWindow(vector<int> &nums, int k)
// {
//     int n = nums.size();
//     if (n == 1)
//     {
//         return nums;
//     }
//     int temp = -10000000;
//     vector<int> res;
//     if (n <= k)
//     {
//         for (auto i : nums)
//         {
//             if (i > temp)
//             {
//                 temp = i;
//             }
//         }
//         res.push_back(temp);
//         return res;
//     }
//     for (int i = 0, j = k - 1; i < (n + 1 - k) && j < n; i++,j++){
//         for (int i1 = i; i1 <= j;i1++){
//             if(nums[i1]>temp){
//                 temp = nums[i1];
//             }
//         }
//         res.push_back(temp);
//         temp = -100000;
//     }
//     return res;
// }
// };

class Solution
{
private:
    class MyQueue
    {
    public:
        deque<int> que;
        void pop(int value)
        {
            if (!que.empty() && value == que.front())
            {
                que.pop_front();
            }
        }
        void push(int value)
        {
            while (!que.empty() && value > que.back())
            {
                que.pop_back();
            }
            que.push_back(value);
        }
        int get_front()
        {
            return que.front();
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        MyQueue que;
        vector<int> res;
        int n = nums.size();
        // 先将初始前k个元素加入单调队列
        for (int i = 0; i < k && i < n; i++)
        {
            que.push(nums[i]);
        }
        // 将初始前k个元素的最大值放入结果数组中
        res.push_back(que.get_front());
        for (int i = k; i < n; i++)
        {
            que.pop(nums[i - k]); // 移除滑动窗口最前面的元素
            que.push(nums[i]);    // 将最新的窗口元素进队
            res.push_back(que.get_front());
        }
        return res;
    }
};
// @lc code=end