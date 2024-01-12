/*
 * @lc app=leetcode.cn id=909 lang=cpp
 *
 * [909] 蛇梯棋
 */
// @lc code=start
class Solution {
public:
  int count = 0;
  void backtracking(vector<vector<int>> &board, int &current, int &n,int next) {
    if (current == n) {
      return;
    }
    countt++;
    current = next;
    next=
  }
  int snakesAndLadders(vector<vector<int>> &board) { int n = board.size(); }
};
// @lc code=end