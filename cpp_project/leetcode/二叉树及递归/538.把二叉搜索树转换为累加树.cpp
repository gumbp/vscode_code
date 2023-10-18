/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    void calcu_node_value(TreeNode *root, int &value)
    {
        if (root == nullptr)
        {
            return;
        }
        calcu_node_value(root->right, value);
        root->val = value + root->val;
        value = root->val;
        calcu_node_value(root->left, value);
    }
    TreeNode *convertBST(TreeNode *root)
    {
        int value = 0;
        calcu_node_value(root, value);
        return root;
    }
};
// @lc code=end