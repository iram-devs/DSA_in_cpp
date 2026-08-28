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
    int difference = INT_MAX;
    int prev = -1;
    void inorder(TreeNode* root)
    {
        if(root == NULL) return;
        inorder(root->left);
        if(prev!=-1) difference = min(difference , abs(root->val - prev));
        prev = root->val;
        inorder(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return difference;

    }
};
int main()
{
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(6);
    root->right = new TreeNode(15);
    root->left->left= new TreeNode(4);
    root->left->right = new TreeNode(8);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(18);

    Solution obj;
    int ans = obj.getMinimumDifference(root);
    cout<<ans<<endl;
    return 0;

}