// @before-stub-for-debug-begin
#include "commoncppproblem450.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
class Solution
{
public:
    void find_target_node(TreeNode *&root, TreeNode *parent, int &key)
    {
        // 如若找不到key结点 表明无需删除 直接返回
        if (root == nullptr)
        {
            return;
        }
        if (root->val == key)
        {
            // 若为叶子结点  判断root为parent的左孩子还是右孩子,将对应的parent指针置空即可。
            if (root->left == nullptr && root->right == nullptr)
            {
                if (parent->left == root)
                {
                    parent->left = nullptr;
                }
                else
                {
                    parent->right = nullptr;
                }
                return;
            }
            // root的左子树为空  则将parent的对应指针指向root的右子树的根节点 返回
            else if (root->left == nullptr && root->right)
            {
                if (parent)
                {
                    if (root == parent->left)
                    {
                        parent->left = root->right;
                    }
                    else
                    {
                        parent->right = root->right;
                    }
                    return;
                }
                root = root->right;
                return;
            }
            // root的右子树为空 则将parent的对应指针指向root的左子树的根节点
            else if (root->right == nullptr && root->left)
            {
                if (parent)
                {
                    if (parent->right == root)
                    {
                        parent->right = root->left;
                    }
                    else
                    {
                        parent->left = root->left;
                    }
                    return;
                }
                root = root->left;
                return;
            }
            // 若root左右孩子都在,则将root结点的值用root的后继或前驱元素值替代 同时删除该后继或前驱结点
            // 这里使用前驱结点替代
            else
            {
                TreeNode *temp = root->left;
                TreeNode *pre = root;
                while (temp->right)
                {
                    pre = temp;
                    temp = temp->right;
                }
                //while循环结束后  temp为root结点的前驱元素  pre为temp的父节点
                root->val = temp->val;
                // temp已经是root的左子树中最右下的结点 所以右孩子一定为空 左孩子则不一定
                // 因此 删除temp结点后 temp的父节点pre应指向temp的左孩子
                // 仍需判断tmep为pre的左孩子还是右孩子？
                if (pre->left == temp)
                {
                    pre->left = temp->left;
                    return;
                }
                pre->right = temp->left;
                return;
            }
        }
        // 向右递归
        else if (root->val < key)
        {
            find_target_node(root->right, root, key);
        }
        //向左递归
        else
        {
            find_target_node(root->left, root, key);
        }
    }
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        else if (root->val == key && root->left == nullptr && root->right == nullptr)
        {
            return nullptr;
        }
        find_target_node(root, nullptr, key);
        return root;
    }
};
// @lc code=end
