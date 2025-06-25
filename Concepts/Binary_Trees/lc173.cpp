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

// Brute force
// Write down the inorder traversal (As in BST, inorder is sorted)
// Whenever next() is called, print the element where the pointer is facing
// If the pointer goes more than the array size, then we can return false when hasnext() is called.
class BSTIterator {
private:
    vector<int> inorder;
    void getInorder(TreeNode* root, vector<int>& inorder){
        if (root == nullptr) return;
        getInorder(root->left, inorder);
        inorder.push_back(root->val);
        getInorder(root->right, inorder);
    }
    int i = 0;

public:
    BSTIterator(TreeNode* root) {
        getInorder(root, inorder);
    }
    
    int next() {
        if (i == inorder.size()) return -1;
        int val = inorder[i];
        i++;
        return val;
    }
    
    bool hasNext() {
        if (i >= inorder.size()) return false;
        return true;
    }
};

// TC - O(N) for generating the array, O(1) for next and O(1) for hasNext
// SC - O(2N) Stack space + space to store the array


//Optimal
// Instead of storing the entire tree O(N) space, we can iteratively do inorder, with some slight modifications
// SC reduces to O(H)
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
    
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        if (temp->right != nullptr) pushleft(temp->right, st);
        return temp->val;
    }
    
    bool hasNext() {
        return (!st.empty());
    }
};
// TC O(N)
// SC O(1) on average


