/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        // vector<vector<int>> res;
        // vector<int> temp;
        // queue<TreeNode *> my_que;
        // queue<TreeNode *> my_que1;
        // if (root == nullptr)
        // {
        //     return {};
        // }
        // my_que.push(root);
        // while (!my_que.empty() || !my_que.empty())
        // {
        //     while (!my_que.empty())
        //     {
        //         TreeNode *node = my_que.front();
        //         my_que.pop();
        //         temp.push_back(node->val);
        //         if (node->left)
        //         {
        //             my_que1.push(node->left);
        //         }
        //         if (node->right)
        //         {
        //             my_que1.push(node->right);
        //         }
        //     }
        //     res.push_back(temp);
        //     temp.clear();
        //     my_que = my_que1;
        //     queue<TreeNode *> q;
        //     my_que1 = q;
        // }
        // return res;

        // 优化版本
        vector<vector<int>> res;
        queue<TreeNode *> my_que;
        if (root)
        {
            my_que.push(root);
        }
        while (!my_que.empty())
        {
            int size = my_que.size();
            vector<int> temp;
            for (int i = 0; i < size; i++)
            {
                TreeNode *a = my_que.front();
                temp.push_back(a->val);
                my_que.pop();
                if (a->left)
                {
                    my_que.push(a->left);
                }
                if (a->right)
                {
                    my_que.push(a->right);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};
// @lc code=end
