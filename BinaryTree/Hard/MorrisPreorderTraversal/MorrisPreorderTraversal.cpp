#include<iostream>
#include<vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0),left(nullptr),right(nullptr){}
    TreeNode(int x): val(x),left(nullptr),right(nullptr){}
    TreeNode(int x, TreeNode* left , TreeNode* right): val(x),left(left),right(right){}
};
class Solution{
    public:
    vector<int> MorrisPreorder(TreeNode* root)
    {
      vector<int> preorder;
      TreeNode* curr = root;
      while(curr!=NULL)
      {
        if(curr->left == NULL)
        {
            preorder.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            TreeNode* prev = curr->left;
            while(prev->right != NULL && prev->right!=curr)
            {
                prev=prev->right;
            }
            if(prev->right == NULL)
            {
                prev->right = curr;
                preorder.push_back(curr->val);
                curr=curr->left; 
            }
            else
            {
                prev->right = NULL;
                curr=curr->right;
            }
        }
      }
      return preorder;
    }
};
int main()
{
    
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->left->right = new TreeNode(7);
    root->left->left = new TreeNode(11);
    root->left->right = new TreeNode(4);

    Solution obj;
    vector<int> ans = obj.MorrisPreorder(root);
    cout<<" Morris Preorder Traversal\n";
    for(int x : ans)
    {
        cout<<x<<" ";
    }
    //output : 3 9 11 4 20 15 7
    return 0;
}
/*
                       3
                     /   \
                    9     20
                   / \     /
                  11  4   15
                          \
                          7
*/