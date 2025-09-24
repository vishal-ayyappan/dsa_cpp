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

//Balanced Tree Check (the difference b/w the left and the right subtree is atmost 1)
bool balanced = true;

int getHeight (Node* root){
    if (root == nullptr) return 0;
    int left = getHeight(root->left);
    int right = getHeight(root->right);
    if (abs(left - right) > 1) balanced = false;
    return 1 + max(left, right);
}

bool isBalanced(Node* root) {
    getHeight(root);
    return balanced;
}

//One more way
int getHeight (Node* root){
    if (root == nullptr) return 0;
    int left = getHeight(root->left);
    int right = getHeight(root->right);
    if (left == -1 || right == -1) return -1;
    if (abs(left - right) > 1) return -1;
    return 1 + max(left, right);
}

bool isBalanced(Node* root) {
    int val = getHeight(root);
    if (val == -1) return false;
    return true;
}
