/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution {
 public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    // 法一  循环数组遍历
    // 时间复杂度一般 空间复杂度有约  时间换空间了
    // vector<int> res(nums.size(), -1);
    // for (int i = 0; i < nums.size(); i++) {
    //   int j = i + 1;
    //   while (j % nums.size() != i) {
    //     if(nums[i]<nums[j%nums.size()]){
    //       res[i] = nums[j % nums.size()];
    //       break;
    //     }
    //     j++;
    //   }
    // }
    // return res;

    // 法二：其实也可以不扩充nums，而是在遍历的过程中模拟走了两边nums。
    // 将循环转化为单向遍历，妙啊
    vector<int> result(nums.size(), -1);
    if (nums.size() == 0) return result;
    stack<int> st;
    st.push(0);
    for (int i = 1; i < nums.size() * 2; i++) {
      // 模拟遍历两边nums，注意一下都是用i % nums.size()来操作
      if (nums[i % nums.size()] < nums[st.top()])
        st.push(i % nums.size());
      else if (nums[i % nums.size()] == nums[st.top()])
        st.push(i % nums.size());
      else {
        while (!st.empty() && nums[i % nums.size()] > nums[st.top()]) {
          result[st.top()] = nums[i % nums.size()];
          st.pop();
        }
        st.push(i % nums.size());
      }
    }
    return result;
  }
};
// @lc code=end