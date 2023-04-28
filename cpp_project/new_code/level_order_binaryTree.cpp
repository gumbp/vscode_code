#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
  };
 

class Solution {
  public:
    /**
     *
     * @param root TreeNode类
     * @return int整型vector<vector<>>
     */


    void  _levelOrder(TreeNode* root, vector<vector<int> >& x, int deep) {
        if (root == nullptr) {
            return ;
        }
        if(x.size()>deep){
        x[deep].push_back(root ->val);
        }
        else{
            vector<int> v;
            v.push_back(root->val);
            x.push_back(v);
        }
        _levelOrder(root->left, x, deep + 1);
        _levelOrder(root->right, x, deep + 1);
    }


    vector<vector<int> > levelOrder(TreeNode* root) {
        // write code here
        vector<vector<int> > x;
        _levelOrder(root, x, 0);
        return x;
    }
};