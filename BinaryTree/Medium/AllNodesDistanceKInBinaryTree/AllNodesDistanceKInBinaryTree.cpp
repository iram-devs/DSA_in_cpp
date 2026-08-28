#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    void trackParent(TreeNode* root , unordered_map<TreeNode*, TreeNode*>&parent_track)
    {
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty())
        {
            TreeNode* curr = Q.front();
            Q.pop();
            if(curr->left)
            {
              parent_track[curr->left]=curr;
              Q.push(curr->left);
            }
            if(curr->right)
            {
                parent_track[curr->right]= curr;
                Q.push(curr->right);
            }
            
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*> parent_track;
        trackParent(root , parent_track);
        unordered_map<TreeNode* , bool>visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]= true;
        int level =0;
        while(!q.empty())
        {
            int size = q.size();
            if(level++==k) break;
            for(int i=0;i<size;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !visited[curr->left])
                {
                    q.push(curr->left);
                    visited[curr->left]=true;
                }
                if(curr->right && !visited[curr->right])
                {
                    q.push(curr->right);
                    visited[curr->right]=true;
                }
                if(parent_track[curr]&&!visited[parent_track[curr]])
                {
                    q.push(parent_track[curr]);
                    visited[parent_track[curr]]=true;
                }
            }
        }
        vector<int> res;
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            res.push_back(temp->val);
        }
        return res;
    }
};
int main()
{
    TreeNode* root= new TreeNode(12);
    root->left = new TreeNode(11);
    root->right= new TreeNode(10);
    root->left->left = new TreeNode(21);
    root->left->right= new TreeNode(18);
    root->right->left = new TreeNode(13);
    root->right->right= new TreeNode(14);
    root->left->right->left = new TreeNode(17);
    root->left->right->right= new TreeNode(20);

    Solution obj;
    vector<int> ans = obj.distanceK(root , root->left,2);
    for(int x : ans)
    {
        cout<<x<<" ";
    }
 return 0;
}