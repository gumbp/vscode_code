/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
// 空间复杂度过高  可优化
//  class Solution
//  {
//  public:
//      TreeNode *build(TreeNode *node1, TreeNode *node2)
//      {
//          TreeNode *node = new TreeNode();
//          if (node1 == nullptr && node2 == nullptr)
//          {
//              return nullptr;
//          }
//          else if (node1 == nullptr)
//          {
//              node->val = node2->val;
//              node->left = build(node1, node2->left);
//              node->right = build(node1, node2->right);
//          }
//          else if (node2 == nullptr)
//          {
//              node->val = node1->val;
//              node->left = build(node1->left, node2);
//              node->right = build(node1->right, node2);
//          }
//          else
//          {
//              node->val = node1->val + node2->val;
//              node->left = build(node1->left, node2->left);
//              node->right = build(node1->right, node2->right);
//          }
//          return node;
//      }
//      TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
//      {
//          return build(root1, root2);
//      }
//  };
class Solution
{
public:
    void build(TreeNode *node1, TreeNode *parent_node1, TreeNode *node2, TreeNode *parent_node2)
    {
        if (node1 == nullptr && node2 == nullptr)
        {
            return;
        }
        else if (node1 && node2)
        {
            node1->val = node1->val + node2->val;
            parent_node1 = node1;
            parent_node2 = node2;
            build(node1->left, parent_node1, node2->left, parent_node2);
            build(node1->right, parent_node1, node2->right, parent_node2);
        }
        else if (node1 == nullptr)
        {
            node1 = new TreeNode(node2->val);
            // 表明此时a树的左节点为空 而b树的左节点不为空 则开辟a树的左结点并赋值为b树左结点值
            if (parent_node1->left == nullptr && parent_node2->left == node2)
            {
                parent_node1->left = node1;
            }
            else
            {
                parent_node1->right = node1;
            }
            parent_node1 = node1;
            parent_node2 = node2;
            build(node1->left, parent_node1, node2->left, parent_node2);
            build(node1->right, parent_node1, node2->right, parent_node2);
        }
        else
        {
            build(node1->left, parent_node1, node2, parent_node2);
            build(node1->right, parent_node1, node2, parent_node2);
        }
    }
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        TreeNode *real_root = root1;
        TreeNode *parent_node1 = root1;
        TreeNode *parent_node2 = root2;
        if (root1 == nullptr)
        {
            return root2;
        }
        else if (root2 == nullptr)
        {
            return root1;
        }
        build(root1, parent_node1, root2, parent_node2);
        return real_root;
    }
};
// @lc code=end