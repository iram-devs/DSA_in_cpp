#include<iostream>
#include<algorithm>
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
    int ans = 0;
    int heightOfBinaryTree(TreeNode *root)
    {
        if (root==NULL) return 0;
        int left = heightOfBinaryTree(root->left);
        int right = heightOfBinaryTree(root->right);
        ans = max(ans,right+left);
        return 1 + max(right , left);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        heightOfBinaryTree(root);
        return ans;
    }
};
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(4);
    root->right->right->left=new TreeNode(6);

    Solution obj;
    int ans = obj.diameterOfBinaryTree(root);
    cout<<ans<<endl;
    return 0;

}