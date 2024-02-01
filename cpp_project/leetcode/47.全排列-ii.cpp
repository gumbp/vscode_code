/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */
// @lc code=start
class Solution {
public:
  vector<vector<int>> res;
  vector<int> single_res;
  void backtracking(vector<int> &nums, vector<bool> &used) {
    if (single_res.size() == nums.size()) {
      res.push_back(single_res);
    }
    for (int i = 0; i < nums.size(); i++) {
      if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
        continue;
      }
      //used[i]表示在该树枝上是否使用过
      if (used[i] == false) {
        single_res.push_back(nums[i]);
        used[i] = true;
        backtracking(nums, used);
        used[i] = false;
        single_res.pop_back();
      }
    }
  }
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<bool> used(nums.size(), false);
    sort(nums.begin(), nums.end());
    backtracking(nums, used);
    return res;
  }
};
// @lc code=end
