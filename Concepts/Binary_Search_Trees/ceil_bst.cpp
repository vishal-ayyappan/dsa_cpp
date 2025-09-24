#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
    }
};

//Ceil in BST

int findCeil(Node* root, int x) {
    if (root == nullptr) return -1;
    int ceil = INT_MAX;
    Node* temp = root;
    while (temp != nullptr){
        if (temp->data == x) return temp->data;
        if (temp->data < x){
            temp = temp->right;
        }
        else{
            ceil = min(ceil, temp->data);
            temp = temp->left;
        }
    }
    if (ceil == INT_MAX) return -1;
    return ceil;
}