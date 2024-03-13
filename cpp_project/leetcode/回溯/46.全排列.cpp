/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
// @lc code=start
class Solution {
public:
  vector<int> temp_path;
  vector<vector<int>> res;
  void backtracking(vector<int> &nums, vector<bool> &used) {
    if (temp_path.size() == nums.size()) {
      res.push_back(temp_path);
      return;
    }
    for (int i = 0; i < nums.size(); i++) {
      if (used[i] == true) { // path里已经收录的元素 直接跳过
        continue;
      }
      temp_path.push_back(nums[i]);
      used[i] = true;
      backtracking(nums, used);
      temp_path.pop_back();
      used[i] = false;
    }
  }
  vector<vector<int>> permute(vector<int> &nums) {
    vector<bool> used(nums.size(), false);
    backtracking(nums, used);
    return res;
  }
};

// @lc code=end