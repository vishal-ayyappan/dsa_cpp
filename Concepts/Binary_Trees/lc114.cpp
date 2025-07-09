//Flatten Binary Tree to a Linked list

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

//Brute Force

// Get the preorder traversal, and create the required tree (all left to nullptr) based on it.
void getPreorder(TreeNode* root, queue<TreeNode*>& preorder){
    if (root == nullptr) return;
    preorder.push(root);
    getPreorder(root->left, preorder);
    getPreorder(root->right, preorder);
}

void flatten(TreeNode* root) {
    if (root == nullptr) return;
    //Convert to preorder and then form a tree
    queue<TreeNode*> q;
    getPreorder(root, q);
    TreeNode* temp = root;
    q.pop();
    while (!q.empty()){
        temp->left = nullptr;
        temp->right = q.front();
        q.pop();
        temp = temp->right;
    }
}
//TC - O(N) + O(N);
//SC - O(N) + O(N);


//Optimal

//Approach 1
// We have to follow a right left root traversal and have a previous pointer to connect the right side of the root
TreeNode* prevNode = nullptr;

void flattenTree(TreeNode* root){
    if (root == nullptr) return;
    flattenTree(root->right);
    flattenTree(root->left);
    root->left = nullptr;
    root->right = prevNode;
    prevNode = root;
}

void flatten(TreeNode* root) {
    flattenTree(root);
}
// TC - O(N) SC - O(N)


//Approach 2 
// Extension of approach 1, but with stack ds
void flatten(TreeNode* root) {
    if (root == nullptr) return;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()){
        TreeNode* temp = st.top();
        st.pop();
        if (temp->right != nullptr) st.push(temp->right);
        if (temp->left != nullptr) st.push(temp->left);
        if (!st.empty()) temp->right = st.top();
        temp->left = nullptr;
    }
}

//Approach 3 (Using Morris preorder traversal)
void flatten(TreeNode* root) {
    if (root == nullptr) return;
    TreeNode* curr = root;
    while (curr != nullptr){
        if (curr->left == nullptr){
            curr = curr->right;
        }
        else{
            TreeNode* temp = curr->right;
            TreeNode* rightmost = curr->left;
            while (rightmost->right != nullptr){
                rightmost = rightmost->right;
            }
            rightmost->right = temp;
            curr->right = curr->left;
            curr->left = nullptr;
            curr = curr->right;
        }
    }
}
//TC - O(N) 
//SC - O(1)
