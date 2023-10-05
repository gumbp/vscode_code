/*
 * @Author: Mr.Gan
 * @Date: 2023-09-28 12:30:52
 * @Last Modified by:   Mr.Gan
 * @Last Modified time: 2023-09-28 12:30:52
 */
/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
#include <queue>
using namespace std;
class Solution
{
public:
    // 迭代法
    //  int findBottomLeftValue(TreeNode *root)
    //  {
    //      // 层次遍历  从右往左  最后一个入队的自然是深度最大最左下节点
    //      queue<TreeNode *> q;
    //      q.push(root);
    //      while (!q.empty())
    //      {
    //          root = q.front();
    //          q.pop();
    //          if (root->right)
    //          {
    //              q.push(root->right);
    //          }
    //          if (root->left)
    //          {
    //              q.push(root->left);
    //          }
    //      }
    //      return root->val;
    //  }

    /*
    递归三要素：
    1.确定递归参数
    2.确定终止条件
    3.确定单层递归逻辑
    */
//最初题目理解错误  原来是求最底层的节点数中从左往右看的第一个节点的值
    // 递归法
    //  定义全局变量  方便使用
    int maxDepth = INT_MIN; // 记录最大深度
    int result;             // 记录处于最大深度的节点值

    void traversal(TreeNode *root, int depth)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            if (depth > maxDepth)
            {
                maxDepth = depth;
                result = root->val;
            }
            return;
        }
        if (root->left)
        {
            traversal(root->left, depth + 1); //
        }
        if (root->right)
        {
            traversal(root->right, depth + 1);
        }
        return;
    }
    // 即找树的最后一层最左边的值
    int findBottomLeftValue(TreeNode *root)
    {
        traversal(root, 0);
        return result;
    }
};
// @lc code=end
