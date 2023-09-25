/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */
// @lc code=start
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    class mycomparision
    {
    public:
        bool operator()(const pair<int, int> &left, const pair<int, int> &right)
        {
            return left.second > right.second;
        }
    };
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> my_map;
        vector<int> res(k);
        for (const auto &i : nums)
        {
            my_map[i] += 1;
        }
        // 定义小顶堆 扫描所有频率的数值  第一个参数表示元素类型为二元值pair  第二个参数表明堆的底层实现是vector  第三个参数表明比较的规则
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparision> pri_que;
        for (auto it = my_map.begin(); it != my_map.end(); it++)
        {
            pri_que.push(*it);
            if (pri_que.size() > k)
            {
                pri_que.pop();
            }
        }
        for (int i = 0; i < k; i++)
        {
            res[i] = pri_que.top().first;
            pri_que.pop();
        }
        return res;
    }
};
// @lc code=end
