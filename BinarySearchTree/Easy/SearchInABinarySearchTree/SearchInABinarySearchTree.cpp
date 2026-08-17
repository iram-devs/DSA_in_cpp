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
    TreeNode* searchBST(TreeNode* root, int val) {
            if ( root == NULL || root->val == val) return root;
            if( val < root->val)
            {
               return searchBST(root->left , val);
            }
            else
            {
              return searchBST(root->right,val);
            }
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
    TreeNode* ans = obj.searchBST(root , 12);
    cout<<ans->val<<endl;
    return 0;
}
