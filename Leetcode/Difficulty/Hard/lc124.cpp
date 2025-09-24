#include <bits/stdc++.h>
using namespace std;

//Binary Tree Maximum Path Sum

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int getMaxSum(TreeNode* root, int& maxi){
    if (root == nullptr) return 0;
    //Go left
    int left = getMaxSum(root->left, maxi);
    //Go right
    int right = getMaxSum(root->right, maxi);
    int sum = left + right + root->val;
    maxi = max(maxi, sum);
    if (root->val + max(left, right) < 0) return 0;
    return root->val + max(left, right);
}

int maxPathSum(TreeNode* root) {
    int maxi = INT_MIN;
    getMaxSum(root, maxi);
    return maxi;
}