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

TreeNode* getTree(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder,
    int inStart, int inEnd, unordered_map<int, int>& mpp){
        if (postStart > postEnd || inStart > inEnd) return nullptr;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = mpp[postorder[postEnd]];
        //No of nodes to the right of subtree
        int numsRight = inEnd - inRoot;
        root->left = getTree(postorder, postStart, postEnd-numsRight-1, inorder, inStart, inRoot-1, mpp);
        root->right = getTree(postorder, postEnd-numsRight, postEnd-1, inorder, inRoot+1, inEnd, mpp);
        return root;
    }

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = inorder.size();
    //Store all the inorder in the map
    unordered_map<int, int> mpp;
    for (int i=0; i<n; i++){
        mpp[inorder[i]] = i;
    }
    TreeNode* root = getTree(postorder, 0, n-1, inorder, 0, n-1, mpp);
    return root;
}