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
#include<math.h>
using namespace std;
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int height_of_left = isBalanced(root->left)+1;
        int height_of_right = isBalanced(root->right)+1;
        return abs(height_of_left - height_of_right) <= 1;
    }
};
// @lc code=end

