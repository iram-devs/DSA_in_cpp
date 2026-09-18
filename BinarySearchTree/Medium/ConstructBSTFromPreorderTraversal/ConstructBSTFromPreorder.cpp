#include<iostream>
#include<vector>
#include<climits>
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return build(preorder , i , INT_MAX);
    }
    TreeNode* build(vector<int>&preorder , int &i , int bound)
    {
        if(i==preorder.size()||preorder[i]>bound) return NULL;
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = build(preorder , i , root->val);
        root->right = build(preorder , i , bound);
        return root;
    }
};
void inorder(TreeNode* root)
{
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
int main()
{
    vector<int> preorder = {8,5,1,7,11,10,12};
    Solution obj;
    TreeNode* ans = obj.bstFromPreorder(preorder);
    cout<<"Inorder of constructed Tree:"<<endl;
    inorder(ans);
    return 0;
}