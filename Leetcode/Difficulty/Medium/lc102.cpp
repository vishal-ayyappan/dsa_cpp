#include <bits/stdc++.h>
using namespace std;

//Level Order
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//Level Order Traversal
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (root == nullptr) return ans;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){
        int size = q.size();
        vector<int> ds;
        for (int i=0; i<size; i++){
            TreeNode* node = q.front();
            ds.push_back(node->val);
            q.pop();
            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
        }
        ans.push_back(ds);
    }
    return ans;
}