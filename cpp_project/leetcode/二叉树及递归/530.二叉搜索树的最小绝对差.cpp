/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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

/*
题解：二叉搜索树的特性决定了：结点与结点的值的最小绝对值差存在于中序遍历序列相邻的结点之间
因此本题关键在于找出当前结点的前驱元素和后继元素
并依次计算与当前结点绝对值差并取最小值
递归得遍历任意节点与前驱和后继元素的绝对值差  每次记录最小结果
最后返回全局最小值
时间复杂度：O(nlogn)
空间复杂度：O(1)
*/
#include <algorithm>
using namespace std;
class Solution
{
public:
    // 找出当前节点在中序遍历的前驱结点
    TreeNode *find_inorder_pre(TreeNode *root, TreeNode *parent, TreeNode *grandfather)
    {
        // 若左子树为空 则前驱节点为父节点或爷节点或为空
        if (root->left == nullptr)
        {
            if (parent && root->val > parent->val)
            {
                return parent;
            }
            else if (grandfather && root->val > grandfather->val)
            {
                return grandfather;
            }
            else
            {
                return nullptr;
            }
        }
        // 左子树不为空  则前驱节点存在于左子树中的最右下节点
        TreeNode *temp = root->left;
        TreeNode *pre_node = nullptr;
        while (temp)
        {
            pre_node = temp;
            temp = temp->right;
        }
        return pre_node;
    }

    // 找出当前节点在中序遍历的后继结点
    TreeNode *find_inorder_post(TreeNode *root, TreeNode *parent, TreeNode *grandfather)
    {
        // 若右子树为空 则后继节点为父节点或爷节点或为空
        if (root->right == nullptr)
        {
            if (parent && root->val < parent->val)
            {
                return parent;
            }
            else if (grandfather && root->val < grandfather->val)
            {
                return grandfather;
            }
            else
            {
                return nullptr;
            }
        }
        // 右子树不为空  则后继节点存在于右子树中的最左下节点
        TreeNode *temp = root->right;
        TreeNode *post_node = nullptr;
        while (temp)
        {
            post_node = temp;
            temp = temp->left;
        }
        return post_node;
    }

    int find_mini_diff(TreeNode *root, TreeNode *parent, TreeNode *grandfather, int &mini)
    {
        if (root == nullptr)
        {
            return mini;
        }
        TreeNode *left_node = find_inorder_pre(root, parent, grandfather);
        TreeNode *right_node = find_inorder_post(root, parent, grandfather);
        // 不可能一个节点既没有前驱  也没有后继
        if (left_node == nullptr)
        {
            mini = min(mini, abs(root->val - right_node->val));
        }
        else if (right_node == nullptr)
        {
            mini = min(mini, abs(root->val - left_node->val));
        }
        // 既有前驱又有后继
        else
        {
            mini = min(mini, abs(root->val - right_node->val));
            mini = min(mini, abs(root->val - left_node->val));
        }
        int a = find_mini_diff(root->left, root, parent, mini);
        int b = find_mini_diff(root->right, root, parent, mini);
        mini = a > b ? b : a;
        return mini;
    }

    int getMinimumDifference(TreeNode *root)
    {
        int mini = 0xfffffff;
        TreeNode *parent = nullptr;
        TreeNode *grandfather = nullptr;
        return find_mini_diff(root, parent, grandfather, mini);
    }    

};
// @lc code=end