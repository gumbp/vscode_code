/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */
// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<int>> res;
  vector<int> single_res;
  void backtracking(vector<int> &candidates, int &target, int sum,
                    int startindex) {
    if (sum == target) {
      res.push_back(single_res);
      return;
    }
    for (int i = startindex;
         i < candidates.size() && (sum + candidates[i]) <= target; i++) {
      // 若当前选取的元素与之前元素相同  则为保证组合不重复出现 选取下一个元素
      if (i > startindex && candidates[i] == candidates[i - 1]) {
        continue;
      }
      sum += candidates[i];
      single_res.push_back(candidates[i]);
      backtracking(candidates, target, sum, i + 1);
      sum -= candidates[i];
      single_res.pop_back();
    }
  }

  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    if (candidates.size() == 0) {
      return res;
    }
    sort(candidates.begin(), candidates.end());
    backtracking(candidates, target, 0, 0);

    return res;
  }
};
// @lc code=end