#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Serialize and Deserialize Binary Tree
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "#";
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            int n = q.size();
            for (int i=0; i<n; i++){
                TreeNode* temp = q.front();
                q.pop();
                if (temp == nullptr) ans = ans + "#" + ",";
                else ans = ans + to_string(temp->val) + ",";
                if (temp != nullptr){
                    q.push(temp->left);
                    q.push(temp->right);
                }
            }
        }
        ans.pop_back();
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "#") return nullptr;
        stringstream ss(data);
        string token;
        getline(ss, token, ',');
        TreeNode* root = new TreeNode(stoi(token));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            int size = q.size();
            for (int i=0; i<size; i++){
                TreeNode* temp = q.front();
                q.pop();
                //Get left
                getline(ss, token, ',');
                if (token != "#"){
                    temp->left = new TreeNode(stoi(token));
                    q.push(temp->left);
                }
                else{
                    temp->left = nullptr;
                }
                //Get right
                getline(ss, token, ',');
                if (token != "#"){
                    temp->right = new TreeNode(stoi(token));
                    q.push(temp->right);
                }
                else{
                    temp->right = nullptr;
                }
            }
        }
        return root;
    }
    
};

//Using preorder to solve this
class Codec {
private: 
    void getString(TreeNode* root, string& res){
        if (root == nullptr) {
            res += + "#,";
            return;
        }
        res += to_string(root->val) + ",";
        getString(root->left, res);
        getString(root->right, res);
    }
    TreeNode* getTree(stringstream& ss){
        string token;
        if (!getline(ss, token, ',')) return nullptr;
        if (token == "#") return nullptr;
        TreeNode* root = new TreeNode (stoi(token));
        root->left = getTree(ss);
        root->right = getTree(ss);
        return root;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        getString(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "#") return nullptr;
        stringstream ss(data);
        TreeNode* root = getTree(ss);
        return root;
    }
    
};

