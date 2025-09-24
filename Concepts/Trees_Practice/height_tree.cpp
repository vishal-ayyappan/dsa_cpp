#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

//Height of the binary tree
int heightOfTree(TreeNode<int> *root){
    if (root == nullptr) return 0;
    //Go left
    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);
    return 1 + max(left, right);
}

int heightOfBinaryTree(TreeNode<int> *root){
	// Write your code here.
    return heightOfTree(root);
}