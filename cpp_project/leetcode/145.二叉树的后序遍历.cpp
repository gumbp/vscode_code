/*
 * @Author: Mr.Gan 
 * @Date: 2023-09-26 17:30:14 
 * @Last Modified by: Mr.Gan
 * @Last Modified time: 2023-09-26 17:30:35
 */
/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
            get_res(root->left, res);
            get_res(root->right, res);
            res.push_back(root->val);
        }
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;
        get_res(root, res);
        return res;
    }
};
// @lc code=end
