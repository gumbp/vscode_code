/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    int rob(TreeNode *root)
    {
        // dp五部曲
        // 1-确定dp数组及下标含义
        // 2-确定dp数组初值
        // 3-确定dp递推方程
        // 4-确定遍历顺序
        // 5-举例推导dp数组的值

        // 分治，依次遍历左右子树的最优解
        vector<int> res = treversal(root);
        return max(res[0], res[1]);
    }

    vector<int> treversal(TreeNode *root)
    {
        // 返回值是一个 含两元素的数组，其中vec[0]表示不偷取该节点的收益，vec[1]表示偷取该节点的收益
        // 遇到空节点 显然偷与不偷，收益都为0，故返回{0,0}
        if (root == nullptr)
        {
            // 空节点默认未被窃取  返回0
            return {0, 0};
        }
        vector<int> a = treversal(root->left);
        vector<int> b = treversal(root->right);

        // 不偷取该节点，则左右两节点可偷可不偷,取其最大值
        int cur_val1 = max(a[0], a[1]) + max(b[0], b[1]);
        // 偷当前节点，那么左右节点就不能偷，则收益为
        int cur_val2 = root->val + a[0] + b[0];
        // 返回当前节点不偷和偷的两种不收益，供上一层考虑
        return {cur_val1, cur_val2};
    }
};
// @lc code=end