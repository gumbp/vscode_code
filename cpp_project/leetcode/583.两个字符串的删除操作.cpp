// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem583.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */

// @lc code=start
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        /**
        dp五部曲
        1-确定dp数组及下标含义
        2-确定dp递推方程
        3-确定dp初值
        4-确定遍历顺序
        5-手动推导dp数组初值
        //    dp[i][j]表示以word1[i-1] 结尾的字符串和以word2[j-1]结尾的字符串中二者最大的公共子序列个数
        // 递推方程
        // if[word1[i-1]==word2[j-1]
        // dp[i][j] = dp[i - 1][j - 1] + 1
        // else
        //    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
        // 由递推方程得出：dp[i][j]的值由左上值和上值、左值推导得出
        // 故需顺序遍历 从上到下 从左到右
        // 看递推方程  初始值设置肯定都为0
        **/
        vector<vector<int>>
            dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 1; i <= word1.size(); i++)
        {
            for (int j = 1; j <= word2.size(); j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return word1.size() + word2.size() - 2 * dp[word1.size()][word2.size()];
    }
};
// @lc code=end