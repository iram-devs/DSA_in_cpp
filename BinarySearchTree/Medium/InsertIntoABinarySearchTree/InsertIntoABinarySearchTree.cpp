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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        if (val > root->val)
        { 
            if(root->right == NULL) root->right = new TreeNode(val);
             root->right =insertIntoBST(root->right , val);
        }
        if (val < root->val)
        {
            if(root->left == NULL) root->left = new TreeNode(val);
            root->left = insertIntoBST(root->left , val);
        }
        return root;
    }
};
void inorder(TreeNode* root)
{
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
int main()
{
    TreeNode* root = new TreeNode(18);
    root->left =  new TreeNode(10);
    root->right =  new TreeNode(20);
    root->left->left=new TreeNode(8);
    root->left->right=new TreeNode(12);
    root->right->left = new TreeNode(21);
    
    Solution obj;
    TreeNode* ans = obj.insertIntoBST(root , 14);
    inorder(ans);
    return 0;

}