#include<iostream>
#include<stack>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x , TreeNode* left , TreeNode* right):val(x),left(left),right(right){}
};
class BSTIterator{
    private:
    stack <TreeNode*> st;
    public:
    BSTIterator(TreeNode* root)
    {
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
        pushAll(temp->right);
        return temp->val;
    }
    private:
    void pushAll(TreeNode* node)
    {
        for(;node!=NULL;node=node->left)
        {
            st.push(node);
        }
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

    BSTIterator it(root);

    while(it.hasNext())
    {
        cout<<it.next()<<" ";
    }
    return 0;

}