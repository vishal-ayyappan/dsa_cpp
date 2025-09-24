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

//Inorder traversal
void getInorder(vector<int>& ans, Node* root){
    if (root == nullptr) return;
    getInorder(ans, root->left);
    ans.push_back(root->data);
    getInorder(ans, root->right);
}

vector<int> inOrder(Node* root) {
    // Your code here
    vector<int> ans;
    getInorder(ans, root);
    return ans;
}

//Iterative version (Think carefully!!!) (Go left, you reach nullptr, go right and then go left)
vector<int> inOrder(Node* root) {
    // Your code here
    stack<Node*> st;
    vector<int> ans;
    st.push(root);
    Node* node = root;
    while (true){
        if (node != nullptr){
            st.push(node);
            node = node->left;
        }
        else{
            if (st.empty()) break;
            Node* temp = st.top();
            st.pop();
            ans.push_back(temp->data);
            node = temp->right;
        }
    }
    return ans;
}
