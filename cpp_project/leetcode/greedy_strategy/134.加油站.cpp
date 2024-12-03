/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution
{

public:
    // 我的暴力版本 超时
    // bool can_reach(vector<int> &gas, vector<int> &cost, int &start_index)
    // {
    //     int origin_start = start_index;
    //     int remain_gas = gas[start_index];
    //     // 当能走到下一站时进入 循环继续
    //     while (remain_gas >= cost[start_index])
    //     {
    //         // 走到下一站消耗的油量
    //         remain_gas -= cost[start_index];
    //         remain_gas += gas[start_index];
    //         // 更新到达下一加油站的索引
    //         start_index = (start_index + 1) % (gas.size());
    //         // 到达下一站后的剩余油量
    //         if (start_index == origin_start)
    //         {
    //             return true;
    //         }
    //     }
    //     return false;
    // }

    // int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    // {
    //     // int start_index;
    //     for (int i = 0; i < gas.size(); i++)
    //     {
    //         // 若当前起点都走不到下一步，则启用下一起点
    //         if (gas[i] < cost[i])
    //         {
    //             continue;
    //         }
    //         // 若从当前起点出发能绕一圈走回原点  则返回该起点
    //         if (can_reach(gas, cost, i))
    //         {
    //             return i;
    //         }
    //     }
    //     return -1;
    // }

    // 思想策略：
    // 可以换一个思路，首先如果总油量减去总消耗大于等于零那么一定可以跑完一圈，
    // 说明 各个站点的加油站 剩油量rest[i]相加一定是大于等于零的。
    // 每个加油站的剩余量rest[i]为gas[i] - cost[i]。
    // i从0开始累加rest[i]，和记为curSum，一旦curSum小于零，说明[0, i]区间都不能作为起始位置，
    // 因为这个区间选择任何一个位置作为起点，到i这里都会断油，那么起始位置从i+1算起，再从0计算curSum。
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int currentSum = 0;
        int totalSum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            // currentSum未更新时表示刚走到索引i处时汽油的存量，加上(gas[i]-cost[i])表示从索引i到索引i+1时的剩余油量
            currentSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if (currentSum < 0)
            {
                start = i + 1;
                currentSum = 0;
            }
        }
        if (totalSum >= 0)
        {
            return start;
        }
        return -1;
    }
};

// @lc code=end