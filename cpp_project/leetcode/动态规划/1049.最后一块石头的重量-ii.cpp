/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        // 思路：尽可能将石头分为重量相等的或者相近的两堆，这样粉碎过后剩下的石块质量最小
        // 转化为01背包问题，dp[k]表示容量为k的背包中，所能装的最大石块的质量
        // 问题即求取dp[total_weight/2]的值

        // 动态规划五部曲
        // 1-确定dp数组及下标的值
        // 2-确定dp数组的初始值
        // 3-确定递推方程
        // 4-确定循环遍历的顺序
        // 5-举例推导dp数组

        int sum = 0;
        for (auto i:stones ){
            sum += i;
        }
        int target_weight = sum / 2;
        vector<int> dp(target_weight+1, 0);
        for (int i = 0; i < stones.size();i++){
            for (int j = target_weight; j >= stones[i];j--){
                dp[j] = max(dp[j],dp[j-stones[i]]+stones[i]);
            }
        }

        return sum - dp[target_weight] - dp[target_weight];
    }
};
// @lc code=end