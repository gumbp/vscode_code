/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        //时间复杂度为O(3n)  空间复杂度O(2n)
        // map<int, int> my_map;
        // map<int, int> my_map1;
        // vector<int> res;
        // for (auto i = 0; i < nums1.size(); i++)
        // {
        //     my_map[nums1[i]] += 1;
        // }
        // for (auto i = 0; i < nums2.size(); i++)
        // {
        //     my_map1[nums2[i]] += 1;
        // }
        // for (auto it = my_map.begin(); it != my_map.end();it++){
        //     if(my_map1[it->first]>0){
        //         res.push_back(it->first);
        //     }
        // }
        // return res;



//时间复杂度为O(n)  空间复杂度O(n)
//牢记元素去重用set
        // 法二：使用unordered_set
        unordered_set<int> my_set1(nums1.begin(), nums1.end());
        unordered_set<int> res;
        for (int num : nums2)
        {
            if (my_set1.find(num) != my_set1.end())
            {
                res.insert(num);
            }
        }
        return vector<int>(res.begin(),res.end());
    }
};
// @lc code=end