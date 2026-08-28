#include<iostream>
#include<stack>
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
    int kthSmallest(TreeNode* root, int k) {
       stack <TreeNode*> st;
       TreeNode* curr = root;
       while (true)
       {
        while(curr != NULL)
        {
          st.push(curr);
          curr = curr->left;
        }
        curr = st.top();
        st.pop();
        k--;
        if(k==0)
        {
            return curr->val;
        }
        curr = curr->right;
       }
    }
};
int main()
{
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    Solution obj;
    int ans = obj.kthSmallest(root,3);
    cout<<ans;
    return 0;
}