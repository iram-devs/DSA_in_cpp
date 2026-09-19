#include<iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x , TreeNode* left , TreeNode* right):val(x),left(left),right(right){}
};
class Solution{
    public:
    TreeNode* inorderPredecessor(TreeNode* root , TreeNode*p)
    {
        TreeNode* predecessor = NULL;
        while(root!=NULL)
        {
            if(p->val<=root->val)
            {
                root=root->left;
            }
            else{
                predecessor = root;
                root=root->right;
            }
        }
        return predecessor;
    }
};
int main()
{
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    Solution obj;
    TreeNode* ans = obj.inorderPredecessor(root , root->right->right);
    cout<<ans->val;
    return 0;
}