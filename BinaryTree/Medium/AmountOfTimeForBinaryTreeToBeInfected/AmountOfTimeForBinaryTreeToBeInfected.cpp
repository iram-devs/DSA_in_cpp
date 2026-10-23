#include<iostream>
#include<queue>
#include<unordered_map>
#include<map>
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
    TreeNode* mapParents(TreeNode* root , int start , unordered_map<TreeNode*,TreeNode*>&mp)
    {
        queue<TreeNode*>q;
        TreeNode* res;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            if(curr->val == start) res = curr;
            if(curr->left)
            {
                mp[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right)
            {
                mp[curr->right]=curr;
                q.push(curr->right);
            }
        }
        return res;
    }
    int countTime(TreeNode* root , TreeNode* beg , unordered_map<TreeNode* , TreeNode*>&parent)
    {
        queue<TreeNode*> q;
        map<TreeNode*,bool>vis;
        q.push(beg);
        vis[beg]=true;
        int time = 0;
        while(!q.empty())
        {
            int flag = 0;
            int size = q.size();
            for(int i = 0 ; i<size ; i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !vis[curr->left])
                {
                    vis[curr->left]=true;
                    flag =1;
                    q.push(curr->left);
                }
                if(curr->right && !vis[curr->right])
                {
                    vis[curr->right]=true;
                    flag =1;
                    q.push(curr->right);
                }
                if(parent[curr] && !vis[parent[curr]])
                {
                    vis[parent[curr]]=true;
                    flag =1;
                    q.push(parent[curr]);
                }
            }
            if(flag==1)time++;
        }
        return time;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode* , TreeNode*> parent;
        TreeNode* beg = mapParents(root,start,parent);
        int time = countTime(root,beg,parent);
        return time;
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
   cout<<"Total time:"<<obj.amountOfTime(root,20);
   return 0;
}