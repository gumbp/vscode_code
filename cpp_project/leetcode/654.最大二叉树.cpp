/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 */
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>
using namespace std;
class Solution
{
public:
    int find_max_pos(vector<int> &nums, int left_side, int right_side)
    {
        int max_pos = left_side;
        for (int i = left_side + 1; i <= right_side; i++)
        {
            if (nums[i] > nums[max_pos])
            {
                max_pos = i;
            }
        }
        return max_pos;
    }
    TreeNode *build(vector<int> &nums, int pos, int left_side, int right_side)
    {
        if (left_side > right_side)
        {
            return nullptr;
        }
        TreeNode *node = new TreeNode(nums[pos]);
        int pos_temp1 = find_max_pos(nums, left_side, pos - 1);
        node->left = build(nums, pos_temp1, left_side, pos - 1);
        int pos_temp2 = find_max_pos(nums, pos + 1, right_side);
        node->right = build(nums, pos_temp2, pos + 1, right_side);
        return node;
    }
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        int pos = find_max_pos(nums, 0, nums.size() - 1);
        return build(nums, pos, 0, nums.size() - 1);
    }
};
// @lc code=end