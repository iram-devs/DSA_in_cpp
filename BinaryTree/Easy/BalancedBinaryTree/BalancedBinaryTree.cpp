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
    int check(TreeNode* root)
    {
        if(root == NULL) return 0;
        int lh = check(root->left);
        int rh = check(root->right);
        if(lh==-1 || rh == -1) return -1;
        if(abs(lh-rh)>1) return -1;
        return max(lh,rh)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        int ans = check(root);
        if(ans==-1) return false;
        else return true;
    }
};
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left=new TreeNode(4);
    root->right=new TreeNode(3);
    root->right->right=new TreeNode(9);
    root->left->left=new TreeNode(7);
    root->right->right->right=new TreeNode(1);

    Solution obj;
    bool ans = obj.isBalanced(root);
    cout<<ans<<endl;
    return 0;

}