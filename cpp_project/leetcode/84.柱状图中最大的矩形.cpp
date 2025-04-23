/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    heights.insert(heights.begin(), 0);
    heights.push_back(0);
    st.push(0);
    int sum = 0;
    for (int i = 1; i < heights.size(); i++) {
      if (heights[i] > heights[st.top()]) {
        st.push(i);
      } else if (heights[i] == heights[st.top()]) {
        st.pop();
        st.push(i);
      } else {
        while (!st.empty() && heights[i] < heights[st.top()]) {
          int mid = st.top();
          st.pop();
          if (!st.empty()) {
            int left = st.top();
            int temp = heights[mid] * (i - left - 1);
            sum = max(sum, temp);
          }
        }
      }
      st.push(i);
    }
    return sum;
  }
};
// @lc code=end
