#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//LCA of Binary Tree
TreeNode* getLCA(TreeNode* root, TreeNode* p, TreeNode* q){
    if (root == nullptr) return nullptr;
    //Check left
    TreeNode* left = getLCA(root->left, p, q);
    //Check right
    TreeNode* right = getLCA(root->right, p, q);
    //If that node, contains one of 2
    if (root->val == p->val || root->val == q->val) return root;
    else if (left != nullptr && right == nullptr) return left;
    else if (left == nullptr && right != nullptr) return right;
    else if (left != nullptr && right != nullptr) return root;
    return nullptr;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* ancestor =  getLCA(root, p, q);
    return ancestor;
}