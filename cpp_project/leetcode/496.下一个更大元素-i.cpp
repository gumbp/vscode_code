/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    vector<int> res1(nums2.size(), -1);
    unordered_map<int, int> my_map;

    stack<int> st;
    st.push(0);
    for (int i = 1; i < nums2.size(); i++) {
      if (nums2[st.top()] >= nums2[i]) {
        st.push(i);
      } else {
        while (!st.empty() && nums2[st.top()] < nums2[i]) {
          int j = st.top();
          res1[j] = i;
          st.pop();
        }
        st.push(i);
      }
    }
    for (int i = 0; i < nums2.size(); i++) {
      int value = nums2[i];
      if (res1[i] == -1) {
        my_map.insert({value, -1});
      } else {
        my_map.insert({value, nums2[res1[i]]});
      }
    }

    for (int i = 0; i < nums1.size(); i++) {
      res.push_back(my_map[nums1[i]]);
    }
    return res;
  }
};
// @lc code=end