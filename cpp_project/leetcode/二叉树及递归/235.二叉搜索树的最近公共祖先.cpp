/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
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
    // 由于是二叉搜索树，则可根据p q结点值与当前结点的大小关系决定向哪个方向递归
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // root为空 或等于p q之一 则表明root为其最近共同祖先
        if (root == nullptr || root == p || root == q)
        {
            return root;
        }
        // 若p q都大于root  则祖先存在于root的右子树中 向右递归
        if (root->val < p->val && root->val < q->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        // 若 p q都小于root 则表明最近共同祖先存在于root的左子树中  向左递归
        else if (root->val > p->val && root->val > q->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        // 否则 p q有一个大于root  一个小于root  则p q 分别存在于root的左右子树中  此时root 即为二者最近共同祖先 直接返回root 结束递归
        else
        {
            return root;
        }
    }
};
// @lc code=end
