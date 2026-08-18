#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
bool isLeaf(TreeNode* root)
{
    return (root->left == NULL && root->right == NULL);
}
void rightBoundary(TreeNode* root , vector<int> &res)
{
    TreeNode* curr = root->right;
    while(curr)
    {
        if(!isLeaf(curr)) res.push_back(curr->val);
        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }
}
void leftBoundary(TreeNode* root , vector<int> &res)
{
    vector<int> temp;
    TreeNode* curr = root->left;
    while(curr)
    {
        if(!isLeaf(curr)) temp.push_back(curr->val);
        if(curr->left) curr= curr->left; 
        else curr = curr->right;
   }
   for(int i = temp.size()-1 ; i>=0 ;i--)
   {
    res.push_back(temp[i]);
   }
}
void addLeaves(TreeNode* root , vector <int> &res)
{
    if(isLeaf(root)) res.push_back(root->val);
    if(root->right) addLeaves(root->right , res);
    if(root->left) addLeaves(root->left , res);
}
vector<int> BoundaryTraversal(TreeNode* root)
{
    vector<int> res ;
    if(!isLeaf(root)) res.push_back(root->val);
    rightBoundary(root , res);
    addLeaves(root , res);
    leftBoundary(root , res);
    return res;
}
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(7);
    root->right->right = new TreeNode(6);
    root->right->right->left = new TreeNode(2);
    root->right->right->left->left= new TreeNode(8);
    root->right->right->left->right = new TreeNode(9);

    vector<int> ans = BoundaryTraversal(root);
    for(int x :ans)
    {
        cout<<x<<" ";
    }

}
//Tree looks like :-
    /*        1
             / \
             3  4
             \   \
             5    6
             /    /
             7    2
                 / \
                 8 9
    */
//Output must be : 1 4 6 2 9 8 7 5 3
