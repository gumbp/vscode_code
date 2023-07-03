#include "tree_data_structure.hpp"

void find_min_data(Binarytree *t,int &key){
    if(t==NULL){
        return;
    }
    if(t->data<key){
        key = t->data;
    }
    find_min_data(t->lchild, key);
    find_min_data(t->rchild, key);
}






int main(){
    Binarytree *t=build_BinaryTree();
    // middle_order_Binarytree(t);
    level_order_Binary(t);
    int key = t->data;
    find_min_data(t, key);
    cout<<"the minial key in the binary tree is "<<key<<endl;
    return 0;
}