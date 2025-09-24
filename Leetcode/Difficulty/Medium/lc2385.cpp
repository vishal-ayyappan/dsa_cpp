#include <bits/stdc++.h>
using namespace std;

//Amount of Time for Binary Tree to Be Infected

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* getStartNode(TreeNode* root, int start){
    //Do a level order
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        if (temp->val == start) return temp;
        if (temp->left != nullptr) q.push(temp->left);
        if (temp->right != nullptr) q.push(temp->right); 
    }
    return nullptr;
}

int getTime(TreeNode* startNode, unordered_map<TreeNode*, TreeNode*>& parent){
    queue<TreeNode*> q;
    unordered_map<TreeNode*, bool> visited;
    int time = 0;
    q.push(startNode);
    visited[startNode] = true;
    while (!q.empty()){
        int n = q.size();
        for (int i=0; i<n; i++){
            TreeNode* temp = q.front();
            q.pop();
            if (temp->left != nullptr && visited.find(temp->left) == visited.end()){
                q.push(temp->left);
                visited[temp->left] = true;
            }
            if (temp->right != nullptr && visited.find(temp->right) == visited.end()){
                q.push(temp->right);
                visited[temp->right] = true;
            }
            if (parent.find(temp) != parent.end() && visited.find(parent[temp]) == visited.end()){
                q.push(parent[temp]);
                visited[parent[temp]] = true;
            }
        }
        time++;
    }
    return time;
}

int amountOfTime(TreeNode* root, int start) {
    //Get the parent nodes
    unordered_map<TreeNode*, TreeNode*> parent;
    //Do a level order traversal to get the parent
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){
        int n = q.size();
        for (int i=0; i<n; i++){
            TreeNode* temp = q.front();
            q.pop();
            if (temp->left != nullptr){
                parent[temp->left] = temp;
                q.push(temp->left);
            }
            if (temp->right != nullptr){
                parent[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }
    //Now do a radial traversal from the target node
    TreeNode* startNode = getStartNode(root, start);
    //A node with a value of start exists in the tree (so start node will not be nullptr)
    int time = getTime(startNode, parent);
    return time-1;
}