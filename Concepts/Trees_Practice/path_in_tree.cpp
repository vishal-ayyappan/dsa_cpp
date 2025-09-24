#include <bits/stdc++.h>
using namespace std;

template <typename T = int>
class TreeNode{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode(){
        if (left != NULL) delete left;
        if (right != NULL) delete right;
    }
};

bool getPath(TreeNode<int> *root, int x, vector<int>& ans){
    if (root == nullptr) return false;
    ans.push_back(root->data);
    if (root->data == x) {
        return true;
    }
    //Go left
    if (getPath(root->left, x, ans)) return true;
    //Go right
    if (getPath(root->right, x, ans)) return true;
    ans.pop_back();
}

vector<int> pathInATree(TreeNode<int> *root, int x){
    vector<int> ans;
    getPath(root, x, ans);
    return ans;
}


