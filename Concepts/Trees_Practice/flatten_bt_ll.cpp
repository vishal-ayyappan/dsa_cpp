#include <bits/stdc++.h>
using namespace std;

//Flatten Binary Tree to Linked List

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//Similar to reverse post order traversal

class Solution {
private:
    TreeNode* prev = nullptr;
public:
void getFlatten(TreeNode* temp){
    if (temp == nullptr) return;
    getFlatten(temp->right);
    getFlatten(temp->left);
    temp->right = prev;
    temp->left = nullptr;
    prev = temp;
}

void flatten(TreeNode* root) {   
    TreeNode* temp = root;
    getFlatten(temp);
}
};