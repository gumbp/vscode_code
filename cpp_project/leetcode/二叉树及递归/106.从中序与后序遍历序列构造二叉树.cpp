/*
 * @Author: Mr.Gan
 * @Date: 2023-09-28 23:22:18
 * @Last Modified by:   Mr.Gan
 * @Last Modified time: 2023-09-28 23:22:18
 */
/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
#include <vector>
using namespace std;
class Solution
{
public:
    // is 表示inorder start 即中序遍历序列的起始位置 其它参数依次类推
    TreeNode *create(vector<int> &inorder, vector<int> &postorder, int is, int ie, int ps, int pe)
    {
        if (ps > pe)
        {
            return nullptr;
        }
        TreeNode *node = new TreeNode(postorder[pe]);
        int pos;
        for (int i = is; i < ie; i++)
        {
            if (inorder[i] == node->val)
            {
                pos = i;
                break;
            }
        }
        
        /*当递归构建左子树时，左子树的根节点在后序遍历结果中的位置为ps+pos-is-1。这是因为左子树的大小为pos-is，
        所以左子树的后序遍历结果的起始位置为ps，结束位置为ps+pos-is-1。
        同样地，当递归构建右子树时，右子树的根节点在后序遍历结果中的位置为pe-ie+pos。
        这是因为右子树的大小为ie-pos，所以右子树的后序遍历结果的起始位置为pe-ie+pos，结束位置为pe-1。
        这样，我们就可以在递归过程中正确地确定左子树和右子树在后序遍历结果中的位置，从而正确地构建整个二叉树。
        */
        node->left = create(inorder, postorder, is, pos - 1, ps, ps + pos - is - 1);
        node->right = create(inorder, postorder, pos + 1, ie, pe - ie + pos, pe - 1);
        return node;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return create(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};
    // @lc code=end
