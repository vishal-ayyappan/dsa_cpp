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
void merge(vector<int>& preorder, int start, int middle, int end){
    int i = start;
    int j = middle+1;
    vector<int> temp;
    while (i<=middle && j<=end){
        if (preorder[i] <= preorder[j]){
            temp.push_back(preorder[i]);
            i++;
        }
        else{
            temp.push_back(preorder[j]);
            j++;
        }
    }
    while (i<=middle){
        temp.push_back(preorder[i]);
        i++;
    }
    while (j<=end){
        temp.push_back(preorder[j]);
        j++;
    }
    int idx = 0;
    for (int i=start; i<=end; i++){
        preorder[i] = temp[idx];
        idx++;
    }
}

void mergeSort(vector<int>& preorder, int start, int end){
    if (start == end) return;
    int middle = start + (end-start)/2;
    mergeSort(preorder, start, middle);
    mergeSort(preorder, middle+1, end);
    merge(preorder, start, middle, end);
}

void getInorderIndex(vector<int> inorder, unordered_map<int,int>& mpp){
    for (int i=0; i<inorder.size(); i++){
        mpp[inorder[i]] = i;
    }
}

TreeNode* getBstTree(vector<int> preorder, int preStart, int preEnd, vector<int> inorder, int inStart, int inEnd,
unordered_map<int,int>& mpp){
    if (preStart > preEnd || inStart > inEnd) return nullptr;
    TreeNode* root = new TreeNode (preorder[preStart]);
    int inRoot = mpp[root->val];
    int size = inRoot - inStart;
    root->left = getBstTree(preorder, preStart+1, preStart+size, inorder, inStart, inStart+size-1, mpp);
    root->right = getBstTree(preorder, preStart+size+1, preEnd, inorder, inStart+size+1, inEnd, mpp);
    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    vector<int> preordercpy;
    preordercpy.assign(preorder.begin(), preorder.end());
    //sort(preorder.begin(), preorder.end());
    mergeSort(preorder, 0, preorder.size()-1);
    unordered_map<int, int> mpp;
    getInorderIndex(preorder, mpp);
    TreeNode* root = getBstTree(preordercpy, 0, preorder.size()-1, preorder, 0, preorder.size()-1, mpp);
    return root;
}

// Optimal Code

// Concept
// As it is a binary search tree, you have to make sure that the nodes' val is less than the upper bound
// We can set the initial upper bound to be INT_MAX;
// We return a nullptr if the value is greater than upper bound.
// As we have been given a preorder, we can traverse from the start and assign it as we go following the above condition

TreeNode* getBstTree(vector<int>& preorder, int& i, int upperBound){
    if (i == preorder.size() || preorder[i] > upperBound) return nullptr;
    int val = preorder[i];
    TreeNode* root = new TreeNode (val);
    i++;
    // When you go to the left, root->val becomes the upper bound for the next node to be inserted
    root->left = getBstTree(preorder, i, root->val);
    // When you go to the right, upper bound will not change as values in the right are always greater than root->val.
    root->right = getBstTree(preorder, i, upperBound);
    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i = 0; //Iterator through the array
    TreeNode* root = getBstTree(preorder, i, INT_MAX);
    return root;
}

//TC - O(N);
//SC - O(N) Stack space