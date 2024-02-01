/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */
// @lc code=start
// 本体难点在于设计巧妙的数据结构，解决可能出现的航班行程重复问题
class Solution {
private:
  // unordered_map<出发机场，map<到达机场，航班次数>>targets
  // 可用于记录同一趟航班飞了多少次  防止遍历过程陷入死循环
  //同时map<string,int>保证了在出发机场一致的前提下，保证了字典顺序最小的到达机场排在前头。
  unordered_map<string, map<string, int>> targets;

  bool backtracking(int tickets_nums, vector<string> &result) {
    if (result.size() == tickets_nums + 1) {
      return true;
    }
    for (pair<const string, int> &target : targets[result[result.size() - 1]]) {
      if (target.second > 0) { // 判断该行程是否仍未算入路径中
        result.push_back(target.first);
        target.second--;
        if (backtracking(tickets_nums, result)) {
          return true;
        }
        result.pop_back();
        target.second++;
      }
    }
    return false;
  }

public:
  vector<string> findItinerary(vector<vector<string>> &tickets) {
    targets.clear();
    vector<string> result;
    for (const vector<string> &vec : tickets) {
      // targets[vec[0]]表示targets中键为vec[0]的键值，而该键值又是一个map<string,int>类型，故targets[vec[0]][vect[1]]表示访问到嵌套map中的int值
      targets[vec[0]][vec[1]]++;
    }
    result.push_back("JFK");
    backtracking(tickets.size(), result);
    return result;
  }
};
// @lc code=end