/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    void get_res(TreeNode *root, vector<int> &res)
    {

        if (root)
        {
            res.push_back(root->val);
            get_res(root->left, res);
            get_res(root->right, res);
        }

    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        get_res(root, res);
        return res;
    }
};
// @lc code=end
