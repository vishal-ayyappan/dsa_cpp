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

vector<int> inOrder(Node* root) {
    vector<int> inorder;
    if (root == nullptr) return inorder;
    Node* curr = root;
    while (curr != nullptr){
        if (curr->left == nullptr){
            inorder.push_back(curr->data);
            curr = curr->right;
        }
        else{
            Node* temp = curr->left;
            while (temp->right != nullptr && temp->right != curr){
                //Go right till the end
                temp = temp->right;
            }
            //Attach the link
            if (temp->right == nullptr){
                temp->right = curr;
                curr = curr->left;
            }
            //If you come back again, remove the node
            //temp->right == curr
            else{
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    } 
    return inorder;   
}