#include<iostream>
#include<vector>
#include<map>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.size()==0) return NULL;
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        TreeNode* root = build(preorder , 0 , preorder.size()-1 , inorder , 0 , inorder.size()-1 , mp);
        return root;
    }
    TreeNode* build(vector<int>&preorder , int preStart , int preEnd , vector<int> &inorder , int inStart , int inEnd , map<int,int>&mp)
    {
        if(preStart > preEnd || inStart > inEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int rootidx = mp[root->val];
        int numsLeft = rootidx - inStart;
        root->left = build(preorder , preStart+1 , preStart+numsLeft , inorder , inStart , rootidx-1 , mp);
        root->right = build(preorder , preStart+numsLeft+1 , preEnd , inorder , rootidx+1 , inEnd , mp);
        return root;
    }
};
void inorderTraversal(TreeNode* root)
{
    if(root == NULL) return;
    inorderTraversal(root->left);
    cout<<root->val<<" ";
    inorderTraversal(root->right);
}
int main()
{
    vector<int>inorder = {10 , 30 , 20 , 40 , 60 , 50 , 70};
    vector<int>preorder ={40 , 30 , 10 , 20 , 50 , 60 , 70};
    
    Solution obj;
    TreeNode* ans = obj.buildTree(preorder , inorder);
    cout<<"Inorder Traversal of tree formed :"<<endl;
    inorderTraversal(ans);
    return 0;
}