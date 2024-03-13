// @before-stub-for-debug-begin
#include "commoncppproblem90.h"
#include <string>
#include <vector>
using namespace std;
// @before-stub-for-debug-end
/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */
// @lc code=start
class Solution {
public:
  vector<vector<int>> res;
  vector<int> single_res;
  void backtracking(vector<int> &nums, int startIndex, vector<bool> used) {
    res.push_back(single_res);
    if (startIndex >= nums.size()) {
      return;
    }
    for (int i = startIndex; i < nums.size(); i++) {
        //used[i-1]==false表示在横向遍历上（for循环），存在重复元素,需要跳过该元素
      if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
        continue;
      }
      single_res.push_back(nums[i]);
      //used[i]==true表示在纵向遍历上，该元素访问过,只需在横向遍历中去重即可
      used[i] = true;
      backtracking(nums, i + 1,used);
      single_res.pop_back();
      used[i] = false;
    }
  }

  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<bool> used(nums.size(), false);
    // used数组记录数据的不同访问方式 used
    backtracking(nums, 0, used);
    return res;
  }
};
// @lc code=end