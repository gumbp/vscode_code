/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */

// @lc code=start
class Solution
{
public:
    int monotoneIncreasingDigits(int n)
    {

        // 题目要求小于等于N的最大单调递增的整数，那么拿一个两位的数字来举例。
        // 例如：98，一旦出现strNum[i - 1] > strNum[i]的情况（非单调递增），首先想让strNum[i - 1]--，然后strNum[i]给为9，这样这个整数就是89，即小于98的最大的单调递增整数。
        // 这一点如果想清楚了，这道题就好办了。
        // 此时是从前向后遍历还是从后向前遍历呢？
        // 从前向后遍历的话，遇到strNum[i - 1] > strNum[i]的情况，让strNum[i - 1]减一，但此时如果strNum[i - 1]减一了，可能又小于strNum[i - 2]。
        // 这么说有点抽象，举个例子，数字：332，从前向后遍历的话，那么就把变成了329，此时2又小于了第一位的3了，真正的结果应该是299。
        // 那么从后向前遍历，就可以重复利用上次比较得出的结果了，从后向前遍历332的数值变化为：332 -> 329 -> 299
        // 确定了遍历顺序之后，那么此时局部最优就可以推出全局，找不出反例，试试贪心。

        // 将数字转换为字符串，方便截取每一位
        string strNum = to_string(n);
        // flag用来记录从哪一位开始后面赋值为9，初始默认为str.size(),防止原数字本就符合规则的情况下
        // 在第二个for循环被赋值为9
        int flag = strNum.size() ;
        for (int i = strNum.size() - 1; i > 0; i--)
        {
            if (strNum[i - 1] > strNum[i])
            {
                strNum[i - 1]--;
                // 一旦当前位的数值比前一位数值小，则前一位数值减一，从当前位到最后一位，都要赋值为9
                flag = i;
            }
        }
        for (int i = flag; i < strNum.size(); i++)
        {
            strNum[i] = '9';
        }
        return stoi(strNum);
    }
};
// @lc code=end
