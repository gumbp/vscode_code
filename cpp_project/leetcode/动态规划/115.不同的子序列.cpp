/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */
// @lc code=start
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        // 递归五部曲
        // 1确定dp数组及下标含义
        // 2.确定dp递推方程
        // 3.确定dp数组初值
        // 4.确定dp数组遍历顺序
        // 5.手动推导dp数组的值
        // dp[i][j]表示以s[i-1]结尾的s的子串，及以t[i-1]结尾的t的子串中，t字串在s字串中出现的个数
        /**
         *@brief
         分析：
         当s[i - 1] 与 t[j - 1]相等时，dp[i][j]可以有两部分组成。
         一部分是用s[i - 1]来匹配，那么个数为dp[i - 1][j - 1]。
         即不需要考虑当前s子串和t子串的最后一位字母，所以只需要 dp[i-1][j-1]。
        一部分是不用s[i - 1]来匹配，个数为dp[i - 1][j]。
        当s[i-1]与t[j-1]不相等时候，dp[i][j]只能等于dp[i-1][j] 即删除s[i-1]，回退使用前s[i-2]个子序列匹配
        即 s[i - 1] == t[j - 1]
                dp[i][j] = dp[i - 1][j - 1] + dp[i-1][j];
            s[i - 1] ！= t[j - 1]
                dp[i][j] = p[i - 1][j]
        由递推公示得知:
        dp[i][j]由上方和左上方推导
        d[i][0]表示从s 统计 出现空字符串序列的最大个数 自然默认为1
        dp[0][j]表示从空字符串s中的序列统计 出现字符串t的最大个数
         *
         */
        vector<vector<size_t>> dp(s.size() + 1, vector<size_t>(t.size() + 1, 0));
        // 初始化
        for (int i = 0; i <= s.size(); i++)
            dp[i][0] = 1;

            // dp[0][0]特殊 应设置为1  寓意从空字符串中 匹配空字符串的最大序列个数为1

        for (int j = 1; j <= t.size(); j++)
            dp[0][j] = 0;

        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= t.size(); j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[s.size()][t.size()];
    }
};
// @lc code=end