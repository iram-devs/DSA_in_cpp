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
    int leftheight(TreeNode* root)
    {
        int h =0;
        while(root!=NULL)
        {
            h++;
            root=root->left;
        }
        return h;

    }
    int rightheight(TreeNode* root)
    {
        int h =0;
        while(root!=NULL)
        {
            h++;
            root= root->right;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int lh = leftheight(root);
        int rh = rightheight(root);

        //if perfect binary tree then [nodes = 2^lh - 1]
        if(lh==rh) return (1<<lh)-1;
        
        return 1 + countNodes(root->left)+countNodes(root->right);
    }
};
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(6);
    root->right->left = new TreeNode(7);
    root->right->right= new TreeNode(8);

    Solution obj;
    int ans = obj.countNodes(root);
    cout<<ans<<endl;
    return 0;
}