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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0) return NULL;
        map<int , int> mp;
        for(int i= 0;i<inorder.size();i++)
        { 
            mp[inorder[i]]=i;
        }
        TreeNode* root = build(postorder , 0 , postorder.size()-1 , inorder , 0 , inorder.size()-1 , mp);
        return root;
    }
    TreeNode* build(vector<int> &postorder , int postStart , int postEnd , vector<int> &inorder , int inStart , int inEnd , map<int , int>&mp)
    {
        if(inStart>inEnd || postStart>postEnd) return NULL;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int rootidx = mp[root->val];
        int numsLeft = rootidx - inStart;
        root->left = build(postorder , postStart , postStart+numsLeft - 1 , inorder , inStart , rootidx -1 , mp );
        root->right = build(postorder , postStart+numsLeft , postEnd-1 , inorder , rootidx+1 , inEnd , mp);
        return root;
    }
};
void inorderTraversal(TreeNode* root)
{
    if(root==NULL) return;
    inorderTraversal(root->left);
    cout<<root->val<<" ";
    inorderTraversal(root->right);
}
int main()
{
    vector<int> inorder = { 10 , 20 , 30 , 40 , 50 , 60 , 70};
    vector<int> postorder = {10 , 30 , 20 , 50 , 70 , 60 ,40};

    Solution obj;
    TreeNode* ans = obj.buildTree(inorder , postorder);
    inorderTraversal(ans);
    return 0;
}