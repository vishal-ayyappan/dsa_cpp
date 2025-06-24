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


// Optimal Solution

// Concept
// Just like a normal binary search, where you store the next element greater than the target.
// Using the same concept, you can do inorder predecessor
// TC -- O(H) SC -- O(1)


int inOrderSuccessor(TreeNode *root, TreeNode *x) {
    int ans = -1;
    if (root == nullptr) return ans;
    TreeNode* temp = root;
    while (temp != nullptr){
        if (temp->val <= x->val){
            temp = temp->right;
        }
        else{
            ans = temp->val;
            temp = temp->left;
        }
    }
    return ans;
}