#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    //Constructor
    TreeNode (int val_){
        val = val_;
        left = nullptr;
        right = nullptr;
    }
};


// Concept
// As it is a binary search tree, you have to make sure that the nodes' val is less than the upper bound
// We can set the initial upper bound to be INT_MAX;
// We return a nullptr if the value is greater than upper bound.
// As we have been given a preorder, we can traverse from the start and assign it as we go following the above condition


// Optimal Code
TreeNode* getBstTree(vector<int>& preorder, int& i, int upperBound){
    if (i == preorder.size() || preorder[i] > upperBound) return nullptr;
    int val = preorder[i];
    TreeNode* root = new TreeNode (val);
    i++;
    // When you go to the left, root->val becomes the upper bound for the next node to be inserted
    root->left = getBstTree(preorder, i, root->val);
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i = 0; //Iterator through the array
    TreeNode* root = getBstTree(preorder, i, INT_MAX);
    return root;
}