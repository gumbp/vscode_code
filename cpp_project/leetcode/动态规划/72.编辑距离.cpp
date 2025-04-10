/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
 public:
  int minDistance(string word1, string word2) {
    /*
    dp五部曲
    1.确定dp数组及下标值
    2.确定dp递推方程
    3.根据dp递推方程确定dp数组初值
    4.根据递推方程确定遍历顺序
    5.手动推算dp数组值

    dp[i][j]表示以word1[i-1]结尾的字符串1转成以word[j-1]结尾的字符串2所需的最少操作
    递推方程为：
    if word1[i-1]==word2[j-1]
        dp[i][j]=dp[i-1][j-1]

        if (word1[i - 1] != word2[j - 1])，此时就需要编辑了，如何编辑呢？
            dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1)

    操作一：word1删除一个元素，那么就是以下标i - 2为结尾的word1 与
j-1为结尾的word2的最近编辑距离 再加上一个操作。 即 dp[i][j] = dp[i - 1][j] + 1;

    操作二：word2删除一个元素，那么就是以下标i - 1为结尾的word1 与
j-2为结尾的word2的最近编辑距离 再加上一个操作。 即 dp[i][j] = dp[i][j - 1] + 1;

    这里有同学发现了，怎么都是删除元素，添加元素去哪了。
word2添加一个元素，相当于word1删除一个元素，例如 word1 = "ad" ，word2 =
"a"，word1删除元素'd' 和 word2添加一个元素'd'，变成word1="a", word2="ad"

    操作三：替换元素，word1替换word1[i - 1]，使其与word2[j -
1]相同，此时不用增删加元素。 可以回顾一下，if (word1[i - 1] == word2[j -
1])的时候我们的操作 是 dp[i][j] = dp[i - 1][j - 1] 对吧。
那么只需要一次替换的操作，就可以让 word1[i - 1] 和 word2[j - 1] 相同。
所以 dp[i][j] = dp[i - 1][j - 1] + 1;所以取三者最小值


    关于初始化：
dp[0][j]表示空字符串变成有j个长度的字符串所需的操作数 显然需要j次操作
dp[i][0]表示i个长度的字符串变成空字符串所需最小操作数 显然那需要i次
dp[0][0]显然为0
    */
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
    for (int i = 1; i <= word1.size(); i++) {
      dp[i][0] = i;
    }
    for (int j = 1; j <= word2.size(); j++) {
      dp[0][j] = j;
    }

    for (int i = 1; i <= word1.size(); i++) {
      for (int j = 1; j <= word2.size(); j++) {
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = min(dp[i - 1][j] + 1,
                         min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1));
        }
      }
    }
    return dp[word1.size()][word2.size()];
  }
};
// @lc code=end
// @lc code=end
