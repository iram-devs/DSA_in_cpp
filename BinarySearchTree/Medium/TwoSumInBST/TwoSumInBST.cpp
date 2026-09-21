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
class BSTIterator{
    stack<TreeNode*> st;
    bool reverse = true;
    
    public:
    BSTIterator(TreeNode* root , bool isReverse)
    {
        reverse = isReverse;
        pushAll(root);
    }
    bool hasNext()
    {
        return !st.empty();
    }
    int next()
    {
        TreeNode* temp = st.top();
        st.pop();
        if(!reverse) pushAll(temp->right);
        else pushAll(temp->left);
        return temp->val;
    }
    private:
    void pushAll(TreeNode* node)
    {
        for(;node!=NULL;)
        {
            st.push(node);
            if(reverse==true)
            {
                node = node->right;
            } 
            else
            {
                node = node->left;
            }
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator l(root , false);
        BSTIterator r(root , true);
        int i = l.next();
        int j = r.next();
        while(i<j)
        {
            if(i+j == k) return true;
            else if(i+j < k) i=l.next();
            else j = r.next();
        }
        return false;
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

    int target;
    cout<<"Enter target to be searched: ";
    cin>>target;
    Solution obj;
    bool ans = obj.findTarget(root , target);
    if(ans==true) cout<<"target found!"<<endl;
    else cout<<"Not found!"<<endl;

    return 0;
    
}