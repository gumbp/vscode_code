// @before-stub-for-debug-begin
#include "commoncppproblem98.h"
#include <string>
#include <vector>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool judge(TreeNode *root, int *lower, int *upper)
    {
        if (root == nullptr)
        {
            return true;
        }
        if (upper && root->val >= *upper)
        {
            return false;
        }
        if (lower && root->val <= *lower)
        {
            return false;
        }
        // 依次递归检查当前结点值与上界和下界的大小关系 验证是否满足bst的特性  结合二叉树图以及debug来分析递归执行过程更直观
        return judge(root->left, lower, &(root->val)) && judge(root->right, &(root->val), upper);
    }
    bool isValidBST(TreeNode *root)
    {
        return judge(root, nullptr, nullptr);
    }
};
// @lc code=end