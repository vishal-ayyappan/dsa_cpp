#include <bits/stdc++.h>
using namespace std;

// Vertical order traversal
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> ans;
    if (root == nullptr) return ans;
    //You have to keep track of the x and y coordinates
    map<int, map<int, multiset<int>>> mpp;
    //mpp[x][y].insert() --> stores the element in the (x, y) coordinate
    //Do a level order traversal
    queue<pair<TreeNode*, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while (!q.empty()){
        int size = q.size();
        for (int i=0; i<size; i++){
            auto item = q.front();
            q.pop();
            TreeNode* node = item.first;
            int x = item.second.first;
            int y = item.second.second;
            mpp[x][y].insert(node->val);
            if (node->left != nullptr) q.push({node->left, {x-1, y+1}});
            if (node->right != nullptr) q.push({node->right, {x+1, y+1}});
        }
    }
    //Iterate through the x coordinate
    for (auto& it : mpp){
        vector<int> ds;
        for (auto& s : it.second){
            multiset<int> vals = s.second;
            for (int val : vals){
                ds.push_back(val);
            }
        }
        ans.push_back(ds);
    }
    return ans;
}