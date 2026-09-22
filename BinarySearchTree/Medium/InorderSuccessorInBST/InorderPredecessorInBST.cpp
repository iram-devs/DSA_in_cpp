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
    TreeNode* inoderSuccessor(TreeNode* root , TreeNode* p)
    {
        TreeNode* successor = NULL;
        while(root!=NULL)
        {
            if(p->val>=root->val)
            {
                root=root->right;
            }
            else
            {
                successor=root;
                root=root->left;
            }
        }
        return successor;
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
    TreeNode* ans = obj.inoderSuccessor(root , root->left->right);
    cout<<ans->val<<endl;
    return 0;

}