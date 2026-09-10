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
    int cnt = 0;
    pair<int,int> dfs(TreeNode* root)
    {
        if(root == NULL) return {0,0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;

        if(root->val == sum/count)
        {
            cnt++;
        }
        return {sum , count};
    }
    int averageOfSubtree(TreeNode* root) {
         dfs(root);
         return cnt;
    }
};
int main()
{
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(8);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(6);

    Solution obj;
    int ans = obj.averageOfSubtree(root);
    cout<<ans<<endl;
    return 0;
   
}

/*              4
               / \ 
              8   5
             / \   \ 
            0   1   6
*/