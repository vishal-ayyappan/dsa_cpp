#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//Zig Zag Traversal
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    //Do a simple level order traversal
    queue<TreeNode*> q;
    vector<vector<int>> ans;
    if (root == nullptr) return ans;
    q.push(root);
    while (!q.empty()){
        int size = q.size();
        vector<int> ds;
        for (int i=0; i<size; i++){
            TreeNode* temp = q.front();
            q.pop();
            ds.push_back(temp->val);
            if (temp->left != nullptr) q.push(temp->left);
            if (temp->right != nullptr) q.push(temp->right);
        }
        ans.push_back(ds);
    }
    //You have to reverse the odd values row
    int n = ans.size();
    for (int i=1; i<n; i+=2){
        reverse(ans[i].begin(), ans[i].end());
    }
    return ans;
}