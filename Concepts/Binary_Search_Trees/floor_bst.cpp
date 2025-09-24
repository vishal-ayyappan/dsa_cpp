#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    //Constructor
    Node(int x){
        data = x;
    }
};

//Floor in BST
int floor(Node* root, int x) {
    if (root == nullptr) return -1;
    Node* temp = root;
    int floor = INT_MIN;
    while (temp != nullptr){
        if (temp->data == x) return x;
        //If it is greater, you move left
        if (temp->data > x) temp = temp->left;
        else{
            floor = max(floor, temp->data);
            temp = temp->right;
        }
    }
    if (floor == INT_MIN) return -1;
    return floor;
}