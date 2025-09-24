#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    //Get the parent for each node
    unordered_map<TreeNode*, TreeNode*> mpp;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){
        int n = q.size();
        for (int i=0; i<n; i++){
            TreeNode* temp = q.front();
            q.pop();
            if (temp->left != nullptr){
                mpp[temp->left] = temp;
                q.push(temp->left);
            }
            if (temp->right != nullptr){
                mpp[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }
    //Once you do the BFS traversal, go radially from the target node, to get the nodes at distance k
    //This is similar to BFS in graph
    unordered_map<TreeNode*, bool> visited;
    queue<TreeNode*> new_q;
    new_q.push(target);
    visited[target] = true;
    while (!new_q.empty() && k > 0){
        int n = new_q.size();
        for (int i=0; i<n; i++){
            TreeNode* temp = new_q.front();
            new_q.pop();
            //For each node, check left, right and up
            if (temp->left != nullptr && visited.find(temp->left) == visited.end()){
                new_q.push(temp->left);
                visited[temp->left] = true;
            } 
            if (temp->right != nullptr && visited.find(temp->right) == visited.end()) {
                new_q.push(temp->right);
                visited[temp->right] = true;
            }
            if (mpp.find(temp) != mpp.end() && visited.find(mpp[temp]) == visited.end()) {
                new_q.push(mpp[temp]);
                visited[mpp[temp]] = true;
            }
        }
        k--;
    }
    vector<int> ans;
    while (!new_q.empty()){
        ans.push_back(new_q.front()->val);
        new_q.pop();
    }
    return ans;
}