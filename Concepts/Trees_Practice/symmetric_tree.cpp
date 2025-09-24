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

bool checkIsSymmetric(TreeNode* a, TreeNode* b){
    if (a == nullptr && b == nullptr) return true;
    if (a == nullptr || b == nullptr) return false;
    if (a->val != b->val) return false;
    //Go left for a and right for b
    if (!checkIsSymmetric(a->left, b->right)) return false;
    if (!checkIsSymmetric(a->right, b->left)) return false;
    return true;
}

bool isSymmetric(TreeNode* root) {
    if (root == nullptr) return true;
    return checkIsSymmetric(root->left, root->right);
}