/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n<=0){
//             return 0;
//         }
//         else if(n==1||n==2){
//             return n;
//         }
//         else {
//             return climbStairs(n - 1) + climbStairs(n - 2);
//         }

//     }
// };

// class Solution
// {
// public:
//     int climbStairs(int n)
//     {
//         vector<int> dp(n + 1, 0);
//         dp[1] = 1;
//         dp[2] = 2;
//         for (int i = 3; i <= n; i++)
//         {
//             dp[i] = dp[i - 1] + dp[i - 2];
//         }
//         return dp[n];
//     }
// };



class Solution {
public:
    int climbStairs(int n) {
    if(n<=2){
        return n;
    }
    int pre1 = 1;
    int pre2 = 2;
    for (int i = 3; i <= n;i++){
        int cur = pre1 + pre2;
        pre1 = pre2;
        pre2 = cur;//即此时  pre2存储的是n=i的方法
    }
    return pre2;
    }
};

// @lc code=end
