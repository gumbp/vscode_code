/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
// class Solution {
// 暴力版本 部分测试用例超时
//  public:
//   vector<int> dailyTemperatures(vector<int>& temperatures) {
//     vector<int> answer(temperatures.size(), 0);
//     for (int i = 0; i < temperatures.size() - 1; i++) {
//       int j = i + 1;
//       int count = 0;
//       while (
//              j <= temperatures.size() - 1&&temperatures[j] <=
//              temperatures[i]) {
//         j++;
//       }
//       if (j == temperatures.size()) {
//         continue;
//       }
//       else{
//         answer[i] = j - i;
//       }
//     }
//     return answer;
//   }
// };

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> answer(temperatures.size(), 0);
    stack<int> st;
    st.push(0);
    for (int i = 1; i < temperatures.size(); i++) {
      if (temperatures[st.top()] >= temperatures[i]) {
        st.push(i);
      } else {
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
          int j = st.top();
          answer[j] = i - j;
          st.pop();
        }
        st.push(i);
      }
    }
    return answer;
  }
};
// @lc code=end
