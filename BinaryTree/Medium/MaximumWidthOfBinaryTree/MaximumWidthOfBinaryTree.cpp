#include<iostream>
#include<queue>
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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        queue<pair<TreeNode* , long long>>q;
        q.push({root , 0});
        while(!q.empty())
        {
           int size = q.size();
           int mmin = q.front().second;
           int first , last;
           for(int i =0 ;i<size ;i++)
           {
            long long curr_idx = q.front().second - mmin;
            TreeNode* curr = q.front().first;
            q.pop();
            if(i==0) first = curr_idx;
            if(i==size -1) last = curr_idx;
            if(curr->left) q.push({curr->left , curr_idx*2 +1});
            if(curr->right) q.push({curr->right , curr_idx*2+2});
           }
           ans = max(ans , last-first+1);
        }
        return ans;
    }
};
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->right = new TreeNode(7);
    root->left->left->right = new TreeNode(8);
    root->right->right->right = new TreeNode(9);

    Solution obj;
    int ans = obj.widthOfBinaryTree(root);
    cout<<ans<<endl;
    return 0;
    
}
/*        1
         /  \
        2     3
       / \     \
     4    5     6
     \           \
     8            9

*/