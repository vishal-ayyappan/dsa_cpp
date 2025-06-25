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

// Brute Force
// Get the inorder traversal
// Sort it
// Compare it with original inorder traversal
void getInorder(TreeNode* root, vector<int>& inorder){
    if (root == nullptr) return;
    getInorder(root->left, inorder);
    inorder.push_back(root->val);
    getInorder(root->right, inorder);
}

void rightTree(TreeNode* root, int& i, vector<int>& inorder){
    if (i == inorder.size() || root == nullptr) return;
    rightTree(root->left, i, inorder);
    if (root->val != inorder[i]) root->val = inorder[i];
    i++;
    rightTree(root->right, i, inorder);
}   

void recoverTree(TreeNode* root) {
    vector<int> inorder;
    getInorder(root, inorder);
    sort(inorder.begin(), inorder.end());
    int i = 0;
    rightTree(root, i, inorder);
}

// TC - O(N) + O(NlogN) + O(N)
// SC - O(N) + O(N) + O(N)


//Optimal
// During inorder Traversal, keep a hold of the prev element as well
// Core idea - Inorder should be sorted, so iterate through it tho find where it is not sorted, ans
// just swap the values.

TreeNode* startNode = nullptr;
TreeNode* middleNode = nullptr;
TreeNode* endNode = nullptr;

void getSwapNode(TreeNode* root, TreeNode* &prev){
    if (root == nullptr) return;
    getSwapNode(root->left, prev);
    if (prev != nullptr){
        if (root->val < prev->val){
            if (startNode == nullptr && middleNode == nullptr){
                startNode = prev;
                middleNode = root;
            }
            else endNode = root;
        }
    }
    prev = root;
    getSwapNode(root->right,prev);
}

void recoverTree(TreeNode* root) {
    TreeNode* prev = nullptr;
    startNode = middleNode = endNode = nullptr;
    getSwapNode(root, prev);
    if (endNode != nullptr) swap(startNode->val, endNode->val);
    else swap(startNode->val, middleNode->val);
}

//TC - O(N)
//SC - O(N) recursive stack space