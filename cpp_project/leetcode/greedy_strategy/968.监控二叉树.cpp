/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
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
    // 思路：贪心：尽可能在一个节点上装一个摄像头能够监控到它的子节点和父节点；
    // 按照这个思路的话，首先叶子结点不装摄像头，并且摄像头要隔两层装，能使得摄像头数目达到最少
    // 因此必须从底层遍历二叉树，因而选择后序遍历
    // 难点在于：如何每隔两个节点安装摄像头，其实需要状态专业方程
    // 分析每个节点可能存在的三种状态:
    // 0:该节点无覆盖
    // 1:本节点有摄像头
    // 2:本节点无摄像头但有覆盖
    // 递归终止条件:遇到空节点返回,因为要求叶子结点的状态为无摄像头但有覆盖,即摄像头装在叶子结点的父节点
    // 此时空节点的状态应该是有覆盖,因为要求叶子结点的父节点安装摄像头；如果空节点是无覆盖，那么按处理逻辑叶节点就要装摄像头；
    // 空结点也不能放摄像头，否则叶子节点的父节点就没必要放摄像头了

    // 此时写遍历逻辑
    int post_order(TreeNode *root,int &result)
    {
        if (root == nullptr)
        {
            return 2;
        }
        int left = post_order(root->left,result);
        int right = post_order(root->right,result);
        // 当前节点的左右孩子都有覆盖  则当前节点不需安装摄像头 且标记当前节点无覆盖 返回0
        if (left == 2 && right == 2)
        {
            return 0;
        }
        // 当前节点的左右孩子存在一个无覆盖  则当前节点需安装摄像头 且标记当前节点安装了摄像头 返回1
        else if (left == 0 || right == 0)
        {
            result++;
            return 1;
        }
        // 若当前节点的孩子中有一个装了摄像头 则该节点为覆盖状态 返回2
        else
        {
            return 2;
        }
    }

    int minCameraCover(TreeNode *root)
    {
        int result = 0;
        int state_of_root = post_order(root,result);
        // 判断根节点是否需要安装摄像头
        if(state_of_root==0){
            result++;
        }
        return result;
    }
};

// @lc code=end