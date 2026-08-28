#include<iostream>
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
    long long prev = LLONG_MIN;

    bool inorder(TreeNode* root) {
        if (root == NULL)
            return true;

        if (!inorder(root->left))
            return false;

        if (root->val <= prev)
            return false;

        prev = root->val;

        return inorder(root->right);
    }

    bool isValidBST(TreeNode* root) {
         return inorder(root);
    }
};
int main()
{
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(8);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(9);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(20);

    Solution obj;
    bool ans = obj.isValidBST(root);
    cout<<ans<<endl;
    return 0;
}