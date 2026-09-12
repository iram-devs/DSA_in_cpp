#include<iostream>
using namespace std;
struct TreeNode
{
   int val;
   TreeNode* left;
   TreeNode* right;
   TreeNode(): val(0),left(nullptr),right(nullptr){}
   TreeNode(int x): val(x),left(nullptr),right(nullptr){} 
   TreeNode(int x , TreeNode* left , TreeNode* right): val(x),left(left), right(right){}
};
class Solution{
    public:
    int CeilInBST(TreeNode* root , int k) //to find ceil in BST
    {
        int ceil = -1;
        while(root!=NULL)
        {
            if(root->val == k)
            {
                ceil = root->val;
                return ceil;
            }
            if(root->val>k)
            {
                ceil = root->val;
                root = root->left;
            }
            else{
                root=root->right;
            }
        }
        return ceil;
    }
};
int main()
{
    TreeNode* root = new TreeNode(35);
    root->left = new TreeNode(23);
    root->right = new TreeNode(45);
    root->left->left = new TreeNode(12);
    root->left->right = new TreeNode(28);
    root->right->left = new TreeNode(40);
    root->left->right->left = new TreeNode(25);
    root->right->left->left = new TreeNode(39);
    root->right->left->right = new TreeNode(42);
    
    Solution obj;
    int ans = obj.CeilInBST(root , 24);
    cout<<"Ceil value: "<<ans<<endl;
    return 0;
}

/*         35
           / \
        23     45
       / \     / 
     12  28   40
         /     / \
        25    39 42
*/