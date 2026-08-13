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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL) return 1 + minDepth(root->right);
        if(root->right==NULL) return 1+minDepth(root->left);
        return 1+ min(minDepth(root->left),minDepth(root->right));
    }
};
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(11);
    root->right->left = new TreeNode(9);
    root->right->left->left = new TreeNode(7);

    Solution obj;
    int ans = obj.minDepth(root);
    cout<<ans<<endl;
    return 0;

}