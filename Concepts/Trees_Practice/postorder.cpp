#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = nullptr;
        right = nullptr;
    }
}; 

//Post Order Traversal
void getPostOrder(Node* root, vector<int>& ans){
    if (root == nullptr) return;
    getPostOrder(root->left, ans);
    getPostOrder(root->right, ans);
    ans.push_back(root->data);
}

vector<int> postOrder(Node* root) {
    vector<int> ans;
    getPostOrder(root, ans);
    return ans;
}

//Iterative traversal
vector<int> postOrder(Node* root) {
    vector<int> ans;
    stack<Node*> st;
    while (!st.empty()){
        Node* node = st.top();
        ans.push_back(node->data);
        st.pop();
        if (node->left != nullptr) st.push(node->left);
        if (node->right != nullptr) st.push(node->right);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
