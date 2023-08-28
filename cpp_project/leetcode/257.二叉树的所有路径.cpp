// @before-stub-for-debug-begin
#include "commoncppproblem257.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    void find_path_vector(TreeNode *root, vector<string> &path, string &single_path)
    {
        if (root != nullptr)
        {
            single_path += to_string(root->val);

            // 当该节点为叶子结点时  将已经寻得路径添加到数组中
            if (root->right == nullptr && root->left == nullptr)
            {
                path.push_back(single_path);
            }
            else
            {
                single_path.append("->");
                string temp = single_path;//temp用于暂存当前节点所遍历的路径 当进行递归调用时 single.path会更改
                find_path_vector(root->left, path, single_path);
                find_path_vector(root->right, path, temp);
            }
        }
        // return path;
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> result;
        string a = "";
        find_path_vector(root, result, a);
        return result;
    }
};
// @lc code=end
