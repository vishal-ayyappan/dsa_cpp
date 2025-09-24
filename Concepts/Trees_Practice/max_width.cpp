#include <bits/stdc++.h>
using namespace std;

//Maximum Width of Binary Tree

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int widthOfBinaryTree(TreeNode* root) {
    //Do a level order traversal and mark each node
    if (root == nullptr) return 0;
    long long maxi = 1;
    queue<pair<TreeNode*, long long>> q;
    q.push({root, 0});
    while (!q.empty()){
        int size = q.size();
        long long first = -1;
        long long last = -1;
        for (int i=0; i<size; i++){
            auto item = q.front();
            q.pop();
            TreeNode* temp = item.first;
            long long node_no = item.second;
            if (i == 0) first = node_no;
            if (i == size-1) last = node_no;
            if (temp->left != nullptr){
                int new_node_no = 2*node_no + 1;
                q.push({temp->left, new_node_no});
            }
            if (temp->right != nullptr){
                int new_node_no = 2*node_no + 2;
                q.push({temp->right, new_node_no});
            }
        }
        if (first == last) continue;
        maxi = max(maxi, last-first+1);
    }
    return maxi;
}