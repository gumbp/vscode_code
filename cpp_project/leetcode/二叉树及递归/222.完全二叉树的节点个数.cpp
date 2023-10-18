/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
#include <queue>
using namespace std;
// 层次遍历 时间复杂度 O(n)  空间复杂度O(n)
class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        int count = 0;
        if (root == nullptr)
        {
            return count;
        }
        queue<TreeNode *> my_que;
        my_que.push(root);
        while (!my_que.empty())
        {
            TreeNode *temp = my_que.front();
            my_que.pop();
            count++;
            if (temp->left)
            {
                my_que.push(temp->left);
            }
            if (temp->right)
            {
                my_que.push(temp->right);
            }
        }
        return count;
    }

    // 递归写法
    // int countNodes(TreeNode *root)
    // {
    //     if (root == nullptr)
    //     {
    //         return 0;
    //     }
    //     int left_nodes = countNodes(root->left);
    //     int right_nodes = countNodes(root->right);
    //     return left_nodes + right_nodes + 1;
    // }
};
// @lc code=end
