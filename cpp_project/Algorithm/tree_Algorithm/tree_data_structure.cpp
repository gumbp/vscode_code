#include "tree_data_structure.hpp"
// 二叉树的建立
Binarytree *build_BinaryTree()
{
    int data;
    cout << "请输入节点的值（-1表示为空节点）" << endl;
    cin >> data;
    if(data==-1){
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
    cout << T->data<<"  ";
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

//层次遍历二叉树  使用队列实现
void level_order_Binary(Binarytree *T){
    if(T==nullptr){
        return;
    }

    queue<Binarytree *> q;
    q.push(T);
    while(!q.empty()){
        Binarytree *current = q.front();//front返回队列中第一个元素
        q.pop();//将队首元素出列
        cout << current->data<< endl;
        //依次将当前节点的左右子节点入队
        if(current->lchild){
            q.push(current->lchild);
        }
        if(current->rchild){
            q.push(current->rchild);
        }

    }
}