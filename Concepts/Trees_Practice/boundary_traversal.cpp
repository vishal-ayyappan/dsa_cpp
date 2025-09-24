#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


bool isLeaf(Node* temp){
    if (temp->left == nullptr && temp->right == nullptr) return true;
    return false;
}

void getLeaves(Node* root, vector<int>& leaves){
    if (root == nullptr) return;
    if (isLeaf(root)) leaves.push_back(root->data);
    getLeaves(root->left, leaves);
    getLeaves(root->right, leaves);
}

vector<int> boundaryTraversal(Node *root) {
    vector<int> ans;
    if (root == nullptr) return ans;
    if (isLeaf(root)){
        ans.push_back(root->data);
        return ans;
    }
    //Go left and add everything until the leaf
    Node* temp = root;
    vector<int> left;
    left.push_back(temp->data);
    temp = temp->left;
    //Get the left (excluding leaf)
    while (temp != nullptr){
        if (!isLeaf(temp)) left.push_back(temp->data);
        //Go left always
        if (temp->left != nullptr) temp = temp->left;
        else temp = temp->right;
    }
    for (int& val : left) ans.push_back(val);
    //Get the leaves
    vector<int> leaves;
    getLeaves(root, leaves);
    for (int leaf : leaves) ans.push_back(leaf);
    //Get the right (excluding leaf)
    vector<int> right;
    Node* node = root;
    right.push_back(node->data);
    node = node->right;
    while (node != nullptr){
        if (!isLeaf(node)) right.push_back(node->data);
        //Go only right 
        if (node->right != nullptr) node = node->right;
        //If right is not there, then go left
        else node = node->left;
    }
    reverse(right.begin(), right.end());
    right.pop_back();
    for (int val : right) ans.push_back(val);
    return ans;
}