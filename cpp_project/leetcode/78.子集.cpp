// @before-stub-for-debug-begin
#include "commoncppproblem78.h"
#include <string>
#include <vector>
using namespace std;
// @before-stub-for-debug-end
/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
// @lc code=start
class Solution {
public:
  vector<vector<int>> res;
  vector<int> single_res;
  void backtracking(vector<int> &nums, int startIndex) {
    if (startIndex == nums.size()) {
      res.push_back(single_res);
      return;
    } else if (single_res.size() > 0) {
      res.push_back(single_res);
    }
    for (int i = startIndex; i < nums.size(); i++) {
      single_res.push_back(nums[i]);
      backtracking(nums, i + 1);
      single_res.pop_back();
    }
  }
  vector<vector<int>> subsets(vector<int> &nums) {
    res.push_back(single_res);
    backtracking(nums, 0);
    return res;
  }
};
// @lc code=end