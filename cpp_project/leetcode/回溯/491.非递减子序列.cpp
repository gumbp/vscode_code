/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 非递减子序列
 */
// @lc code=start
class Solution {
public:
  vector<vector<int>> res;
  vector<int> path;
  void backtracking(vector<int> &nums, int startIndex) {
    if (path.size() > 1) {
      res.push_back(path);
    }
    int used[201] = {0};//单独在每一层初始化验证数组  因为只有在同一层上才不允许元素的重复出现 
    for (int i = startIndex; i < nums.size(); i++) {
      if (path.size() > 0 && path.back() > nums[i] ||
          used[nums[i] + 100] == 1) {
        continue;
      }
      path.push_back(nums[i]);
      used[nums[i] + 100] = 1;
      backtracking(nums, i + 1);
      path.pop_back();
    }
  }

  // 我的版本  只通过部分测试用例
  //   void backtracking(vector<int> &nums, int startIndex, vector<bool> &used,
  //                     int path_size) {
  //     if (path.size() > 1 && path.size() > path_size) {
  //       res.push_back(path);
  //       path_size = path.size();
  //     }
  //     if (startIndex >= nums.size()) {
  //       return;
  //     }
  //     for (int i = startIndex; i < nums.size(); i++) {
  //       if (path.size() == 0) {
  //         path.push_back(nums[i]);
  //       } else if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
  //         continue;
  //       } else if (i > 0 && nums[i] >= nums[i - 1]) {
  //         path.push_back(nums[i]);
  //       }
  //       used[i] = true;
  //       backtracking(nums, i + 1, used, path_size);
  //       used[i] = false;
  //       if (path.size()) {
  //         path.pop_back();
  //       }
  //     }
  //   }

  vector<vector<int>> findSubsequences(vector<int> &nums) {
    backtracking(nums, 0);
    return res;
  }
};
// @lc code=end