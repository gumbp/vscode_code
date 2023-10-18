/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
class Solution
{
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        //递归出口
        if (root == nullptr)
        {
            return 0;
        }
        // 若为叶子结点 直接返回  减少递归层数
        if (!root->left && !root->right)
        {
            return 0;
        }
        //左右中顺序遍历  
        int left_value = sumOfLeftLeaves(root->left);
        //递归体
        if (root->left && !root->left->right && !root->left->left)
        {
            left_value = root->left->val;
        }
        int right_value = sumOfLeftLeaves(root->right);
        return right_value + left_value;
    }
};
// @lc code=end
