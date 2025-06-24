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

class BSTIterator {
private:
    stack<TreeNode*> st;
    void pushleft(TreeNode* root, stack<TreeNode*>& st){
        if (root == nullptr) return;
        while (root != nullptr){
            st.push(root);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushleft(root, st);
    }
    
    TreeNode* next() {
        TreeNode* temp = st.top();
        st.pop();
        if (temp->right != nullptr) pushleft(temp->right, st);
        return temp;
    }
    
    bool hasNext() {
        return (!st.empty());
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