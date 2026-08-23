#include <iostream>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if (root == NULL || root == p ||root ==q) return root;
       TreeNode* left = lowestCommonAncestor(root->left, p , q);
       TreeNode* right = lowestCommonAncestor(root->right , p ,q);
       if(left == NULL) return right;
       else if(right==NULL) return left;
       else return root;
       
    }
};
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(11);
    root->left->right->right = new TreeNode(8);
    root->right->left = new TreeNode(7);
    root->right->left->left = new TreeNode(9);
    root->right->left->right = new TreeNode(13);

    Solution obj;
    TreeNode* ans = obj.lowestCommonAncestor(root , root->left->left,root->left->right->right); //(6,8)
    cout<<ans->val; //o/p : 4
    return 0;
}
//Tree look like below:
/*         1
         /   \
        4     5
       / \   /
      6 11   7
         \   / \
         8  9  13
 */