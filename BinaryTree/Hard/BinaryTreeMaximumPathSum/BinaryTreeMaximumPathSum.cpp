#include <iostream>
#include<climits>
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
    int maxSum(TreeNode* root , int &maxi)
    {
        if(root == NULL) return 0;
        int leftSum = max(0,maxSum(root->left , maxi));
        int rightSum = max(0,maxSum(root->right,maxi));
        maxi = max(maxi , root->val+ leftSum + rightSum);
        return root->val + max(leftSum , rightSum);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxSum(root , maxi);
        return maxi;
    }
};
int main()
{
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(14);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(-7);
    root->right->right->left = new TreeNode(20);
    root->right->right->right = new TreeNode(8);
    root->right->right->left->left = new TreeNode(-10);
    root->right->right->left->right = new TreeNode(-17);

    Solution obj;
    int ans = obj.maxPathSum(root);
    cout<<ans<<endl;
    return 0;  
}