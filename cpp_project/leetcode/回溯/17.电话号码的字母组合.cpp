/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
// @lc code=start
class Solution
{
public:
    vector<string> my_map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    string str;
    void get_res(string &digits, int index)
    {
        if (str.size() == digits.size())
        {
            res.push_back(str);
            return;
        }
        int digit = digits[index] - '0';
        string letters = my_map[digit]; // 取数字对应的字符集
        for (int i = 0; i < letters.size(); i++)
        {
            str.push_back(letters[i]);
            get_res(digits, index + 1);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
        {
            return res;
        }
        get_res(digits, 0);
        return res;
    }
};
// @lc code=end