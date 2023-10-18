/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
// 迭代版
//  class Solution {
//  public:
//      TreeNode* insertIntoBST(TreeNode* root, int val) {
//          TreeNode *pre = nullptr;
//          TreeNode *root_1 = root;
//          TreeNode *temp = new TreeNode(val);
//          if(!root_1){
//              return temp;
//          }
//          while(root_1){
//              if(root_1->val<val){
//                  pre = root_1;
//                  root_1 = root_1->right;
//              }
//              else{
//                  pre = root_1;
//                  root_1 = root_1->left;
//              }
//          }
//          if(val<pre->val){
//              pre->left = temp;
//          }
//          else{
//              pre->right = temp;
//          }
//          return root;
//      }
//  };

// 递归  优化版
// 时间复杂度：O（logn）
// 空间复杂度：O（1）
class Solution
{
public:
    void insert_node(TreeNode *root, TreeNode *node)
    {
        if (root->val < node->val && root->right == nullptr)
        {
            root->right = node;
            return;
        }
        else if (root->val > node->val && root->left == nullptr)
        {
            root->left = node;
            return;
        }
        else if (root->val < node->val)
        {
            insert_node(root->right, node);
        }
        else
        {
            insert_node(root->left, node);
        }
    }
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        TreeNode *temp = new TreeNode(val);
        if (!root)
        {
            return temp;
        }
        insert_node(root, temp);
        return root;
    }
};

// @lc code=end
