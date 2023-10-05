/*
 * @Author: Mr.Gan 
 * @Date: 2023-09-26 17:30:20 
 * @Last Modified by: Mr.Gan
 * @Last Modified time: 2023-09-26 17:30:40
 */
/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
#include <math.h>
using namespace std;
class Solution
{
public:
    int judge(TreeNode *root, bool &ans)
    {
        if (root == nullptr)
        {
            return 0;
        }
        //若已经为false  说明已经不符合平衡二叉树的要求  即刻返回
        if (ans == false)
        {
            return 0;
        }
        int nodes_left = judge(root->left, ans);
        int nodes_right = judge(root->right, ans);
        if (abs(nodes_left - nodes_right) > 1)
        {
            ans = false;
        }

        //返回该节点的高度 即为1+左右子树最大高度
        return 1 + max(nodes_left, nodes_right);
    }
    bool isBalanced(TreeNode *root)
    {
        bool ans = true;
        int temp = judge(root, ans);
        return ans;
    }
};
// @lc code=end