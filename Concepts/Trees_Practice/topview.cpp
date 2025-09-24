#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

//Top view of the binary tree
vector<int> topView(Node *root) {
    //You do the vertical order traversal, only store the x coordinates
    vector<int> ans;
    if (root == nullptr) return ans;
    map<int, int> mpp;
    queue<pair<Node*, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while (!q.empty()){
        auto item = q.front();
        q.pop();
        Node* temp = item.first;
        int x = item.second.first;
        int y = item.second.second;
        if (mpp.find(x) == mpp.end()) mpp[x] = temp->data;
        if (temp->left != nullptr) q.push({temp->left, {x-1, y+1}});
        if (temp->right != nullptr) q.push({temp->right, {x+1, y+1}});
    }
    for (auto& it : mpp) ans.push_back(it.second);
    return ans;
}