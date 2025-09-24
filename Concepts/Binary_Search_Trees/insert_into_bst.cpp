#include <bits/stdc++.h>
using namespace std;

// Insert into a Binary Search Tree

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//You can always insert at the leaf
TreeNode* insertIntoBST(TreeNode* root, int val) {
    TreeNode* newNode = new TreeNode(val);
    if (root == nullptr) return newNode;
    TreeNode* temp = root;
    while (temp != nullptr){
        //Traverse until you go to one of the ends
        if (temp->val >= val){
            //You go left
            if (temp->left != nullptr) temp = temp->left;
            else {
                temp->left = newNode;
                break;
            }  
        }
        else{
            if (temp->right != nullptr) temp = temp->right;
            else{
                temp->right = newNode;
                break;
            }
        }
        //If you reach null, then that is where we insert the node
    }
    return root;
}