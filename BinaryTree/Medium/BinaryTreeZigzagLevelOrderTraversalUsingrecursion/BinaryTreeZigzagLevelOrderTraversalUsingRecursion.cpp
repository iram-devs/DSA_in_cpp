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
    vector<vector<int>>ans;
    int height(TreeNode* root)
    {
        if(root==NULL) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        return 1+max(lh,rh);
    }
    void spiral(TreeNode* root)
    {
        int h = height(root);
        bool flag = false;
        for(int i =1 ;i<=h;i++)
        {
            vector<int>v;
            printgivenlevel(root ,i, flag,v);
            ans.push_back(v);
            flag = !flag;
        }
    }
    void printgivenlevel(TreeNode* root ,int level,bool flag, vector<int>&v)
    {
        if(root == NULL) return;
        if(level==1)
        {
           v.push_back(root->val);
           return;
            
        }
        if(level>1)
        {
            if(flag)
            {
                printgivenlevel(root->right,level-1,flag,v);
                printgivenlevel(root->left,level-1,flag,v);
            }
        
            else
            {
                printgivenlevel(root->left,level-1,flag,v);
                printgivenlevel(root->right,level-1,flag,v);
            }
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root==NULL) return {};
        spiral(root);
        return ans;
         
    }
};
int main()
{
 TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    Solution obj;
    vector<vector<int>> ans = obj.zigzagLevelOrder(root);
    for(int i =0 ;i<ans.size();i++)
    {
        for(int j =0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}