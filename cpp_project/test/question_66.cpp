#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// 对于一个给定的长度为N的整数序列A，它的“子序列”的定义是：A中非空的一段连续的元素（整数）。你要完成的任务是，
// 在所有可能的子序列中，找到一个子序列，该子序列中所有元素的和是最大的（跟其他所有子序列相比）。程序要求你输出这个最大值。
// 本题为典型的滑动窗口最大值。只是窗口大小不固定，需要遍历所有的窗口大小。

// 常规算法  综合下来总的时间复杂度是O(n^2)  超时了
// int getMaxWindowSum(vector<int> &nums, int &k)
// {
//     int result = INT32_MIN;
//     for (int i = 0; i < nums.size() - k; i++)
//     {
//         int sum = 0;
//         for (int j = i; j < k + i; j++)
//         {
//             sum += nums[j];
//         }
//         result = max(result, sum);
//     }
//     return result;
// }

int maxSubarraySum(vector<int> &nums)
{
    int maxSum = INT_MIN;
    int currentSum = 0;
    for (auto num : nums)
    {
        // 比较当前currenSum和currentSum加上当前值 二者谁大  如果currentSum加上当前值大 则currentSum更新为currentSum加上当前值
        // 如果当前值大于(currentSum加上当前值) 则表示currentSum为负数，丢弃之前值，子序列从当前num开始，即currentSum更新为当前值
        currentSum = max(num, currentSum + num);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

int main()
{
    int n;
    vector<int> numbers;
    cin >> n;
    int value;
    int result = INT64_MIN;
    while (n--)
    {
        cin >> value;
        numbers.push_back(value);
    }
    cout << maxSubarraySum(numbers);

    return 0;
}