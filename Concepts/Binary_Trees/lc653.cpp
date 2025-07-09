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

//Brute force (Optimal according to LC)
// Get inorder and do two sum in a sorted array 
void getInorder(TreeNode* root, vector<int>& inorder){
    TreeNode* curr = root;
    while (curr != nullptr){
        if (curr->left == nullptr){
            inorder.push_back(curr->val);
            curr = curr->right;
        }
        else{
            TreeNode* temp = curr->left;
            while (temp->right != nullptr && temp->right != curr){
                temp = temp->right;
            }
            if (temp->right == nullptr){
                temp->right = curr;
                curr = curr->left;
            }
            else{
                temp->right = nullptr;
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
}

bool findTarget(TreeNode* root, int k) {
    vector<int> inorder;
    getInorder(root, inorder);
    int i = 0;
    int j = inorder.size()-1;
    while (i < j){
        int val = inorder[i]+inorder[j];
        if (val == k) return true;
        if (val < k) i++;
        else j--;
    }
    return false;
}

// TC - O(N) + O(N);
// SC - O(N)


//Optimal
// Use the binary search iterator, instead of forming an array. Form a next function and a previous function

class BstIterator{
private:
    stack<TreeNode*> st1;
    stack<TreeNode*> st2;

    void pushleft(TreeNode* root, stack<TreeNode*>& st1){
        if (root == nullptr) return;
        while (root != nullptr){
            st1.push(root);
            root = root->left;
        }
    }

    void pushright(TreeNode* root, stack<TreeNode*>& st2){
        if (root == nullptr) return;
        while (root != nullptr){
            st2.push(root);
            root = root->right;
        }
    }

public:
    BstIterator(TreeNode* root){
        pushleft(root, st1);
        pushright(root, st2);
    }

    int next(){
        TreeNode* temp = st1.top();
        st1.pop();
        if (temp->right != nullptr){
            pushleft(temp->right, st1);
        }
        return temp->val;
    }

    bool hasNext(){
        return (!st1.empty());
    }

    int prev(){
        TreeNode* temp = st2.top();
        st2.pop();
        if (temp->left != nullptr){
            pushright(temp->left, st2);
        }
        return temp->val;
    }

    bool hasPrev(){
        return (!st2.empty());
    }

};


class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        auto c = BstIterator(root);
        int val1 = c.next();
        int val2 = c.prev();
        while (c.hasNext() && c.hasPrev() && val1 < val2){
            int sum = val1 + val2;
            if (val1 + val2 == k) return true;
            if (sum < k) val1 = c.next();
            else val2 = c.prev();
        }
        return false;
    }
};

//TC - O(N/2) + O(1) for next, previous, hasNext, hasPrev
//SC - O(H) + O(H)