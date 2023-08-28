/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> my_map;
        for (int i = 0; i < nums.size();i++)
        {
            if(my_map.find(nums[i])!=my_map.end()){
                return true;
            }
            my_map[nums[i]]=i;
        }
        return false;
    }
};
// @lc code=end

