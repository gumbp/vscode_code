#ifndef TREE_STRUCE
#define TREE_STRUCE
#include <iostream>
#include <queue>
using namespace std;
typedef struct Binarytree
{
    int data;
    Binarytree *lchild;
    Binarytree *rchild;
    Binarytree(int key):data(key),lchild(nullptr),rchild(nullptr){}
};

// 二叉树的建立  递归实现
Binarytree *build_BinaryTree();

// 二叉树的先序遍历
void pre_order_Binarytree(Binarytree *T);

// 二叉树的中序遍历
void middle_order_Binarytree(Binarytree *T);

// 二叉树的后序遍历
void postorder_Binarytree(Binarytree *T);

//层次遍历二叉树  使用队列实现
void level_order_Binary(Binarytree *T);

//找到二叉树中的最小节点值
void find_min_data(Binarytree *t, int &key);


// 计算所给二叉树的叶子节点数
int Count_LeafNode(Binarytree *T);


// 计算所给二叉树的双分支节点个数
int Count_DoubleLeaf(Binarytree *T);

// 计算二叉树所有节点值之和
int Sum_Of_NodeValue(Binarytree *T);

// 计算二叉数中节点值为x的节点数
int Count_Value_X(Binarytree *T, int &x);
#endif
