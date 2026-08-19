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
    TreeNode* buildtree(vector<int>nums , int left , int right)
    {
        if(left>right) return nullptr;
        int mid = left + (right - left)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildtree(nums , left , mid-1);
        root->right = buildtree(nums , mid+1 , right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildtree(nums , 0 , nums.size()-1);
     }
};
void inorder(TreeNode* root)
{
   if(root==NULL) return;
   inorder(root->left);
   cout<<root->val<<" ";
   inorder(root->right);
}
int main()
{
    vector<int> nums = {-2 , 4, 5 , 7 ,10 , 14 , 16};
    Solution obj;
    TreeNode* ans = obj.sortedArrayToBST(nums);
    inorder(ans); //The output  must be same as given vector/array
    return 0;
}
