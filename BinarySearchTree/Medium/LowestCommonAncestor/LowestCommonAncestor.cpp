#include<iostream>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(root == NULL) return NULL;
            if(root->val > p->val && root->val > q->val)
            {
                return lowestCommonAncestor(root->left , p ,q);
            }
            if(root->val < p->val && root->val < q->val)
            {
                return lowestCommonAncestor(root->right , p , q);
            }
            return root;
    }
};
int main()
{
    TreeNode* root = new TreeNode(20);
    root->left =  new TreeNode(10);
    root->right =  new TreeNode(24);
    root->left->left=new TreeNode(8);
    root->left->right=new TreeNode(12);
    root->right->left = new TreeNode(21);
    root->right->right = new TreeNode(30);
   
    Solution obj;
    TreeNode* ans = obj.lowestCommonAncestor(root , root->left->right, root->right->left);
    cout<<ans->val;
    return 0;
}