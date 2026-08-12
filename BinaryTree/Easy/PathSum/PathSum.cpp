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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
        {
            return false;
        }
        if(root->right == NULL && root->left == NULL)
        {
            return (root->val == targetSum);
        }
         return hasPathSum(root->right,targetSum-root->val)||hasPathSum(root->left , targetSum-root->val);
    }
};
int main()
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(7);
    root->right = new TreeNode(4);
    root->left->right= new TreeNode(9);
    root->left->right->left = new TreeNode(11);
    root->right->left = new TreeNode(2);
    root->right->left->left=new TreeNode(1);
    root->right->left->right = new TreeNode(12);
    Solution obj;
    bool ans = obj.hasPathSum(root , 12);
    cout<<ans<<endl;
    return 0;

}