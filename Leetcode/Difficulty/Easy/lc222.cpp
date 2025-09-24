#include <bits/stdc++.h>
using namespace std;

//Count Complete Tree Nodes

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int getLeftHeight(TreeNode* temp){
    int height = 0;
    while (temp != nullptr){
        temp = temp->left;
        height++;
    }
    return height;
}

int getRightHeight(TreeNode* temp){
    int height = 0;
    while (temp != nullptr){
        temp = temp->right;
        height++;
    }
    return height;
}

int getNodes(TreeNode* root){
    if (root == nullptr) return 0;
    int lh = getLeftHeight(root->left);
    int rh = getRightHeight(root->right);
    if (lh == rh) return (2 << lh) - 1;
    return 1 + getNodes(root->left) + getNodes(root->right);
}

int countNodes(TreeNode* root) {
    if (root == nullptr) return 0;
    return getNodes(root);
}