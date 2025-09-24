#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    //Constructor
    Node(int x){
        data = x;
    }
};

vector<int> preOrder(Node* root) {
    vector<int> preorder;
    if (root == nullptr) return preorder;
    Node* curr = root;
    while (curr != nullptr){
        if (curr->left == nullptr){
            preorder.push_back(curr->data);
            curr = curr->right;
        }
        else{
            //Go to the left subtrees' rightmost node
            Node* temp = curr->left;
            while (temp->right != nullptr && temp->right != curr){
                temp = temp->right;
            }
            if (temp->right == nullptr){
                temp->right = curr;
                preorder.push_back(curr->data);
                curr = curr->left;
            }
            else if (temp->right == curr){
                curr = curr->right;
            }
        }
    }
    return preorder;
}