/*
 * @Author: Mr.Gan
 * @Date: 2023-09-28 12:45:43
 * @Last Modified by: Mr.Gan
 * @Last Modified time: 2023-09-28 22:16:10
 */
/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool flag = false;
    void judge(TreeNode *root, int targetSum, int temp_result)
    {
        // 递归出口
        if (flag || !root)
        {
            return;
        }

        // 若为叶子节点  则计算路径之和与目标数是否一致
        if (root->left == nullptr && root->right == nullptr)
        {
            if ((temp_result + root->val) == targetSum)
            {
                // 到该叶子结点  路径之和等于targetSum,则将flag置为true 该层递归结束  返回
                flag = true;
                return;
            }
        }
        // 暗含回溯
        judge(root->left, targetSum, temp_result + root->val);
        judge(root->right, targetSum, temp_result + root->val);
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        judge(root, targetSum, 0);
        return flag;
    }
};
// @lc code=end