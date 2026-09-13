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
    TreeNode* findLastRight(TreeNode* root)
    {
        if(root->right == NULL) return root;
        return findLastRight(root->right);
    }
    TreeNode* helper(TreeNode* root)
    {
        if(root->left == NULL) return root->right;
        if(root->right == NULL) return root->left;
        TreeNode* rightChild = root->right;
        TreeNode* lastRight= findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return root;
        if(root->val == key)
        {
            root = helper(root);
        }
        TreeNode* temp = root;
        while(root!=NULL)
        {
            if(root->val>key)
            {
             if(root->left!=NULL && root->left->val == key)
             {
                 root->left = helper(root->left);
             }
             root=root->left;
            }
            else
            {
                if(root->right!=NULL && root->right->val == key)
                {
                    root->right = helper(root->right);
                }
                root = root->right;
            }

        }
        return temp;
    }
};
void inorderTraversal(TreeNode* root)
{
    if(root==NULL) return;
    inorderTraversal(root->left);
    cout<<root->val<<" ";
    inorderTraversal(root->right);
}
int main()
{
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(14);
    root->right = new TreeNode(25);
    root->left->left = new TreeNode(11);
    root->left->right = new TreeNode(16);
    root->left->right->left = new TreeNode(15);
    root->right->left = new TreeNode(21);
    root->right->right = new TreeNode(28);
    
    //inorder of original tree......
    cout<<"Inorder of original tree:\n";
    inorderTraversal(root);   //output: 11 14 15 16 20 21 25 28

    Solution obj;
    TreeNode*ans = obj.deleteNode(root , 14);

    //inorder after deletion.......
    cout<<"\nInorder after deleting 14:\n";
    inorderTraversal(ans);    // 11 15 16 20 21 25 28

    return 0;
}

/*
                      20
                    /   \
                   14    25
                  /  \   / \ 
                 11  16  21 28
                     /
                     15
*/