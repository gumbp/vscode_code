/*
 * @Author: Mr.Gan
 * @Date: 2023-10-06 19:29:15
 * @Last Modified by:   Mr.Gan
 * @Last Modified time: 2023-10-06 19:29:15
 */
/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // 后序遍历二叉树  遇到如下情况返回
        if (root == nullptr || root == p || root == q)
        {
            return root;
        }
        // 遍历左子树
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        // 遍历右子树
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        // 如若此时left 和right都不为空 则表明在root的左右子树中找到了p和q结点  表明root为二者最近祖先
        if (left != nullptr && right != nullptr)
        {
            return root;
        }
        // 若left为空  right不为空  表明在root的左子树中不存在q和p，而存在于右子树中。此时right即为q和p的最近公共祖先(right本身为p或q)
        else if (left == nullptr && right != nullptr)
        {
            return right;
        }
        // 原因类推上述情况
        else if (left != nullptr && right == nullptr)
        {
            return left;
        }
        // 否则 left和right都为空的情况  表明q和p结点不存在于root树中  直接返回空
        else
        {
            return nullptr;
        }
    }
};
// @lc code=end