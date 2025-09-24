#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

vector<int> bottomView(Node *root) {
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
        mpp[x] = temp->data;
        if (temp->left != nullptr) q.push({temp->left, {x-1, y+1}});
        if (temp->right != nullptr) q.push({temp->right, {x+1, y+1}});
    }
    for (auto& it : mpp){
        ans.push_back(it.second);
    }
    return ans;
}