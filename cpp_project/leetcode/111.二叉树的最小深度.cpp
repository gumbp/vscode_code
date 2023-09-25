/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
// 必须二刷
#include <algorithm>
using namespace std;
class Solution
{
public:
    // 自己的算法  
    int get_min_depth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        else if (root->left == nullptr && root->right == nullptr)
        {
            return 1;
        }
        else if (root->left == nullptr)
        {
            return 1 + get_min_depth(root->right);
        }
        else if (root->right == nullptr)
        {
            return 1 + get_min_depth(root->left);
        }
        else
        {
            int left = get_min_depth(root->left);
            int right = get_min_depth(root->right);
            int depth = min(left, right) + 1;
            return depth;
        }
    }
    int minDepth(TreeNode *root)
    {
        return get_min_depth(root);
    }
};

// class Solution
// {
// public:
//他人思路
//     int get_min_depth(TreeNode *root)
//     {
//         if (root == nullptr)
//         {
//             return 0;
//         }
//         int left_depth = get_min_depth(root->left);
//         int right_depth = get_min_depth(root->right);

//         if (root->right == nullptr && root->left != nullptr)
//         {
//             return left_depth + 1;
//         }
//         if (root->left == nullptr && root->right != nullptr)
//         {
//             return right_depth + 1;
//         }
//         int depth = 1 + min(right_depth, left_depth);
//         return depth;
//     }
//     int minDepth(TreeNode *root)
//     {
//         return get_min_depth(root);
//     }
// };

// @lc code=end