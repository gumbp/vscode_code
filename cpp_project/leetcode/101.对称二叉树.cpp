/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool judge(TreeNode *left, TreeNode *right)
    {
        if (right == nullptr && left == nullptr)
        {
            return true;
        }
        else if (left == nullptr && right)
        {
            return false;
        }
        else if (left && right == nullptr)
        {
            return false;
        }
        else if (right->val != left->val)
        {
            return false;
        }
        // 当左右节点都存在且数值相等的情况下，才做递归
        // 判断外侧节点是否对称
        bool outside = judge(left->left, right->right);
        // 判断内侧节点是否对称
        bool inside = judge(left->right, right->left);
        return outside && inside;
    }

    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        return judge(root->left, root->right);
    }
};
// @lc code=end