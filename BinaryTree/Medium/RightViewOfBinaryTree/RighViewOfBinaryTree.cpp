#include<iostream>
#include<vector>
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
    void printRightView(TreeNode* root , int level , vector<int> &res)
    {
        if(root == NULL) return ;
        if(level == res.size()) res.push_back(root->val);
        printRightView(root->right , level+1 , res);
        printRightView(root->left , level+1 , res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        printRightView(root , 0 , res);
        return res;
    }
};
int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(1);
    root->left->left->right = new TreeNode(4);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;
    vector<int> ans = obj.rightSideView(root);
    for(int x : ans)
    {
        cout<<x<<" ";
    }
    return 0;
}
//tree :
/*    3
     /  \
     9   20
    /   / \
    1   15 7
    \
    4
output : 3 20 7 4
*/