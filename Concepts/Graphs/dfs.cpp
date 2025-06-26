#include<bits/stdc++.h>
using namespace std;

void getDfs(vector<vector<int>>& adj, vector<bool>& visited, vector<int>& ans, int val){
    ans.push_back(val);
    visited[val] = true;
    for (int i=0; i<adj[val].size(); i++){
        int element = adj[val][i];
        if (!visited[element]){
            getDfs(adj, visited, ans, element);
        }
    }
}

vector<int> dfs(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited (n,false);
    vector<int> ans;
    int val = 0;
    getDfs(adj, visited, ans, val);
    return ans;
}

//TC - O(V + 2E)
//SC - O(N) [stack space] + O(N) [for queue] + O(N) [for visited]