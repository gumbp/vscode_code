// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem669.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
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
// class Solution
// {
// public:
//     //
//     TreeNode *delete_node(TreeNode *&root, TreeNode *parent)
//     {
//         // 此时root->val必定大于high或小于low
//         // 且root最多只有一个孩子
//         // 若该结点为叶子节点  则直接删除
//         if (root->left == nullptr && root->right == nullptr)
//         {
//             // 判断root为parent的左孩子还是右孩子
//             if (parent->left == root)
//             {
//                 parent->left = nullptr;
//             }
//             else
//             {
//                 parent->right = nullptr;
//             }
//             return nullptr;
//         }
//         // 若root有一个孩子
//         TreeNode *temp = root->left ? root->left : root->right;
//         // 判断root为parent的左孩子还是右孩子
//         if (parent->left == root)
//         {
//             parent->left = temp;
//         }
//         else
//         {
//             parent->right = temp;
//         }
//         // 回溯 重新判定parent的两个结点是否符合要求
//         return root;
//     }
//     void adjust(TreeNode *&root, int low, int high, TreeNode *parent)
//     {
//         // 采用先序遍历方式 预先处理每个结点
//         //  空结点 则递归终止
//         if (root == nullptr)
//         {
//             return;
//         }
//         // 若结点小于下界 则其左子树结点全小于下界 则将其左子树置空
//         else if (root->val < low)
//         {
//             // root->left = nullptr;
//             root = delete_node(root, parent);
//         }

//         // 若结点大于上界 则其右子树结点全大于上界 则将其右子树置空
//         else if (root->val > high)
//         {
//             // root->right = nullptr;
//             root = delete_node(root, parent);
//         }

//         if (root)
//         {
//             adjust(root->left, low, high, root);
//             adjust(root->right, low, high, root);
//         }
//     }
//     TreeNode *trimBST(TreeNode *root, int low, int high)
//     {
//         TreeNode *virtual_head = new TreeNode(-1);
//         virtual_head->right = root;
//         adjust(root, low, high, virtual_head);
//         return virtual_head->right;
//     }
// };
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr ) return nullptr;
        if (root->val < low) {
            TreeNode* right = trimBST(root->right, low, high); // 寻找符合区间[low, high]的节点
            return right;
        }
        if (root->val > high) {
            TreeNode* left = trimBST(root->left, low, high); // 寻找符合区间[low, high]的节点
            return left;
        }
        root->left = trimBST(root->left, low, high); // root->left接入符合条件的左孩子
        root->right = trimBST(root->right, low, high); // root->right接入符合条件的右孩子
        return root;
    }
};
// @lc code=end