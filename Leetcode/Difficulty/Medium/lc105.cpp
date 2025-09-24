#include <bits/stdc++.h>
using namespace std;

//Construct Binary Tree from Preorder and Inorder Traversal

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode* getTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd,
    unordered_map<int, int>& mpp){
        if (preStart > preEnd || inStart > inEnd) return nullptr;
        TreeNode* root = new TreeNode(preorder[preStart]);
        //Get the inorder nodes index
        int inRoot = mpp[preorder[preStart]];
        int nodes_in_left_subTree = inRoot - inStart;
        root->left = getTree(preorder, preStart+1, preStart+nodes_in_left_subTree, inorder, inStart, inRoot-1, mpp);
        root->right = getTree(preorder, preStart+nodes_in_left_subTree+1, preEnd, inorder, inRoot+1, inEnd, mpp);
        return root;
    }

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    //Inorder traversal, will tell you the alignment
    int n = preorder.size();
    unordered_map<int, int> mpp;
    for (int i=0; i<n; i++) mpp[inorder[i]] = i;
    TreeNode* root = getTree(preorder, 0, n-1, inorder, 0, n-1, mpp);
    return root;
}