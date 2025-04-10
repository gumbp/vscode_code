/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        // dp五部曲
        // 1-确定dp数组及下标含义
        // 2-确定dp数组初值大小
        // 3-确定dp递推方程
        // 4-确定遍历顺序
        // 举例推导dp数组的值
        vector<bool> dp(s.size() + 1, false);
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        // dp[i]=false  表示当前长度为i的字符串 表示可以拆分为一个或者多个
        // 在字典中出现过的单词

        dp[0] = true;
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                string word = s.substr(j, i - j);
                if (wordSet.find(word) != wordSet.end() && dp[j])
                {
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end