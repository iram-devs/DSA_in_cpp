#include<iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x , TreeNode* left , TreeNode* right): val(x),left(left),right(right){}
};
class Solution{
    public:
    int kthSmallestElement(TreeNode* root , int k)
    {
      TreeNode* curr = root;
      int count =0;
      int ans = -1;
      while(curr!=NULL)
      {
        if(curr->left == NULL)
        {
          count++;
          if(count==k)
          {
            ans = curr->val;
            break;
          }
          curr=curr->right;
        }
        else{
            TreeNode* prev=curr->left;
            while(prev->right!=NULL && prev->right->val!=curr->val)
            {
                prev =prev->right;
            }
            if(prev->right == NULL)
            {
                prev->right = curr;
                curr=curr->left;
            }
            else
            {
                prev->right = NULL;
                count++;
                if(count==k)
                {
                    ans = curr->val;
                    break;
                }
                curr=curr->right;
            }
        }
      }
     return ans;
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
    int ans = obj.kthSmallestElement(root,3);
    cout<<ans;
    return 0;
}