#include<iostream>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    bool isMirror(TreeNode *left , TreeNode *right)
    {
        if(left == NULL && right == NULL) return true;
        if(left == NULL || right == NULL) return false;

        return (left->val == right->val)&& 
                isMirror(left->left,right->right)&& 
                isMirror(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return isMirror(root->left,root->right);
    }
};
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    Solution obj;
    bool ans = obj.isSymmetric(root);
    cout<<ans<<endl;
    return 0;

}