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

//Diameter of the binary tree
int getDiameter(TreeNode* root, int& maxi){
    if (root == nullptr) return 0;
    int left = getDiameter(root->left, maxi);
    int right = getDiameter(root->right, maxi);
    maxi = max(maxi, (left+right));
    return 1 + max(left, right);
}

int diameterOfBinaryTree(TreeNode* root) {
    int maxi = 0;
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return 0;
    getDiameter(root, maxi);
    return maxi;
}