/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
class Solution
{
public:
    int maxDepth(TreeNode *root)
    // 递归版本  超时
    //  {
    //      if (root == nullptr)
    //      {
    //          return 0;
    //      }
    //      return (maxDepth(root->left) + 1) > (maxDepth(root->right) + 1) ? (maxDepth(root->left) + 1) : (maxDepth(root->right) + 1);
    //  }

    // 迭代版本  借助队列实现
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
            int size = my_que.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = my_que.front();
                my_que.pop();
                if (temp->left)
                {
                    my_que.push(temp->left);
                }
                if (temp->right)
                {
                    my_que.push(temp->right);
                }
            }
            count++;
        }
        return count;
    }
};
// @lc code=end
