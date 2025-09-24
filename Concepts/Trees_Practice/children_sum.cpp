#include <bits/stdc++.h>
using namespace std;

//Children Sum Property

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

bool isLeaf(Node* temp){
    if (temp->left == nullptr && temp->right == nullptr) return true;
    return false;
}

bool isValid(Node* root){
    if (root == nullptr || isLeaf(root)) return true;
    //Check the condition
    int sum = 0;
    if (root->left != nullptr) sum += root->left->data;
    if (root->right != nullptr) sum += root->right->data;
    if (sum != root->data) return false;
    //Go left
    if (!isValid(root->left)) return false;
    //Go right
    if (!isValid(root->right)) return false;
    return true;
}

int isSumProperty(Node *root) {
    return isValid(root);
}