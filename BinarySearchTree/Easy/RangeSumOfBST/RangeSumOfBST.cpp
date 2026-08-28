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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL) return 0;
        if(root->val>=low && root->val<=high) return root->val + rangeSumBST(root->left , low , high)+rangeSumBST(root->right , low ,high);
        if(root->val <=low)  return rangeSumBST(root->right,low,high);
        else return rangeSumBST(root->left , low , high);
        
    }
};
int main()
{
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(8);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(16);
    root->right->right = new TreeNode(24);

    Solution obj;
    int ans = obj.rangeSumBST(root , 7 , 15);
    cout<<ans<<endl;
    return 0;
}