#include "tree_data_structure.hpp"
// 二叉树的建立
Binarytree *build_BinaryTree()
{
    int data;
    cout << "请输入节点的值（-1表示为空节点）" << endl;
    cin >> data;
    if (data == -1)
    {
        return nullptr;
    }
    Binarytree *T = new Binarytree(data);
    cout << "请输入节点" << data << "的左孩子" << endl;
    T->lchild = build_BinaryTree();
    cout << "请输入节点" << data << "的右孩子" << endl;
    T->rchild = build_BinaryTree();
    return T;
}
// 二叉树的先序遍历
void pre_order_Binarytree(Binarytree *T)
{
    if (T == NULL)
    {
        return;
    }
    cout << T->data;
    pre_order_Binarytree(T->lchild);
    pre_order_Binarytree(T->rchild);
}

// 二叉树的中序遍历
void middle_order_Binarytree(Binarytree *T)
{
    if (T == NULL)
    {
        return;
    }
    middle_order_Binarytree(T->lchild);
    cout << T->data << "  ";
    middle_order_Binarytree(T->rchild);
}

// 二叉树的后序遍历
void postorder_Binarytree(Binarytree *T)
{
    if (T == NULL)
    {
        return;
    }
    cout << T->data;
    postorder_Binarytree(T->lchild);
    postorder_Binarytree(T->rchild);
}
// 层次遍历二叉树  使用队列实现
void level_order_Binary(Binarytree *T)
{
    if (T == nullptr)
    {
        return;
    }

    queue<Binarytree *> q;
    q.push(T);
    while (!q.empty())
    {
        Binarytree *current = q.front(); // front返回队列中第一个元素
        q.pop();                         // 将队首元素出列
        cout << current->data << endl;
        // 依次将当前节点的左右子节点入队
        if (current->lchild)
        {
            q.push(current->lchild);
        }
        if (current->rchild)
        {
            q.push(current->rchild);
        }
    }
}

// 计算所给二叉树的叶子节点数
int Count_LeafNode(Binarytree *T)
{
    static int count = 0;
    if (T != NULL)
    {
        // 若非空节点为叶子结点  则计数加一
        if (T->lchild == NULL && T->rchild == NULL)
        {
            count++;
        }
        // 否则继续遍历左子树和右子树
        else
        {
            Count_LeafNode(T->lchild);
            Count_LeafNode(T->rchild);
        }
    }

    return count;
}

// 计算所给二叉树的双分支节点个数
int Count_DoubleLeaf(Binarytree *T)
{
    static int count = 0;
    if (T != NULL)
    {
        if (T->lchild && T->rchild)
        {
            count++;
        }
        Count_DoubleLeaf(T->lchild);
        Count_DoubleLeaf(T->rchild);
    }
    return count;
}

// 计算二叉树所有节点值之和
int Sum_Of_NodeValue(Binarytree *T)
{
    if (T == NULL)
    {
        return 0;
    }
    return T->data + Sum_Of_NodeValue(T->lchild) + Sum_Of_NodeValue(T->rchild);
}

// 计算二叉数中节点值为x的节点数
int Count_Value_X(Binarytree *T,int &x)
{
    int n=0;
    if (T == NULL)
    {
        return 0;
    }
    if(T->data==x){
        n = 1;
    }
    return n + Count_Value_X(T->lchild, x) + Count_Value_X(T->rchild, x);
}

//计算二叉树中最小节点值
void find_min_value(Binarytree *T){
  static int min=0xfffff;
  if(T==nullptr){
    return min;
  }
  if(T->data<min)
  {
    min=T->data;

  }
  find_min_value(T->lchild);
  find_min_value(T->rchld);
  return min;
}

// }
