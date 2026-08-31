#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";

        string ans = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                ans += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                ans += "N,";
            }
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") return NULL;

        stringstream ss(data);
        string str;

        getline(ss, str, ',');
        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Left child
            getline(ss, str, ',');
            if (str != "N") {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }

            // Right child
            getline(ss, str, ',');
            if (str != "N") {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }

        return root;
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
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    Codec obj;
    string ans = obj.serialize(root);
    cout<<"Serialized tree: "<<ans<<endl;

    Codec obj2;
    TreeNode* ans2 = obj2.deserialize(ans);
    cout<<"Deserialized tree : ";
    inorderTraversal(ans2);
    return 0;


}
 