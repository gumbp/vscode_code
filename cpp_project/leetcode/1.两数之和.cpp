// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem1.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indicate;
        for (int i = 0; i < nums.size();i++){
            //先返回原先数据  防止后续符合条件的元素覆盖 
            if(indicate.find(target-nums[i])!=indicate.end()){
                return {indicate[target - nums[i]], i};
            }
            indicate[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

