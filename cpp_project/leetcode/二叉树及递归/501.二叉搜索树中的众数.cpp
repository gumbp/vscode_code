/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    void inorder_traverse(TreeNode *root, unordered_map<int, int> &my_unordered_map, int &max_fre)
    {
        if (root == nullptr)
        {
            return;
        }
        inorder_traverse(root->left, my_unordered_map, max_fre);
        my_unordered_map[root->val] += 1;
        max_fre = max(max_fre, my_unordered_map[root->val]);
        inorder_traverse(root->right, my_unordered_map, max_fre);
    }
    vector<int> findMode(TreeNode *root)
    {
        vector<int> result;
        int max_fre = 0;
        unordered_map<int, int> my_unordered_map;
        inorder_traverse(root, my_unordered_map, max_fre);
        for (auto [val, fre] : my_unordered_map)
        {
            if (fre == max_fre)
            {
                result.push_back(val);
            }
        }
        return result;
    }
};
// @lc code=end