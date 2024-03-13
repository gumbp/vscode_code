/*
 * @Author: Mr.Gan
 * @Date: 2024-01-02 14:12:13
 * @Last Modified by: Mr.Gan
 * @Last Modified time: 2024-01-02 17:06:44
 */
/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */
// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  vector<string> res;
  void backtracking(string &s, int startIndex, int pointNums) {
    // 若已是ip地址的最后一项  判断最后一项数字是否有效
    if (pointNums == 3) {
      if (ifValids(s, startIndex, s.size() - 1)) {
        res.push_back(s);
      }
      return;
    }

    for (int i = startIndex; i < s.size(); i++) {
      // 判断当前字符是否有效
      if (ifValids(s, startIndex, i)) {
        s.insert(s.begin() + i + 1, '.');
        pointNums++;
        // 递归索引原为i+1，因,额外插入 ‘.’ ,故从i+2处起始
        backtracking(s, i + 2, pointNums);
        pointNums--;
        s.erase(s.begin() + i + 1);
      } 
      //否则  当前项不符合ip地址规范 ，跳出本次递归的for循环
      else {
        break;
      }
    }
  }

  bool ifValids(const string &s, int start, int end) {
    if (start > end) {
      return false;
    }
    if (s[start] == '0' && start != end) {
      return false;
    }
    if (end - start + 1 > 3) {
      return false;
    }
    int value = 0;
    for (int i = start; i <= end; i++) {
      if (s[i] < '0' || s[i] > '9') {
        return false;
      }
      value = value * 10 + s[i] - '0';
    }
    if (value > 255) {
      return false;
    }
    return true;
  }

  vector<string> restoreIpAddresses(string s) {
    backtracking(s, 0, 0);
    return res;
  }
};
// @lc code=end