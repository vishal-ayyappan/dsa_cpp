#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

//Recursive version
void getPreorder(Node* root, vector<int>& ans){
    if (root == nullptr) return;
    ans.push_back(root->data);
    getPreorder(root->left, ans);
    getPreorder(root->right, ans);
}

vector<int> preorder(Node* root) {
    // code here
    vector<int> ans;
    getPreorder(root, ans);
    return ans;
}


//Iterative version
vector<int> preorder(Node* root) {
    // code here
    vector<int> ans;
    stack<Node*> st;
    st.push(root);
    while (!st.empty()){
        Node* val = st.top();
        st.pop();
        ans.push_back(val->data);
        if (val->right != nullptr) st.push(val->right);
        if (val->left != nullptr) st.push(val->left);
    }
    return ans;
}
