#include<bits/stdc++.h>
using namespace std;

//BFS of a graph
vector<int> bfs(vector<vector<int>> &adj) {
    vector<int> ans;
    // BFS starting from node 0
    int n = adj.size();
    //Have a visited array (as the number of nodes are not given)
    vector<bool> visited(n,false);
    //Generate the adjacency list (Already been done in) but generate, if you have
    //been given only edges
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (!q.empty()){
        int m = q.size();
        for (int i=0; i<m; i++){
            int val = q.front();
            q.pop();
            //Push the elements that are connected to the val
            for (int j=0; j<adj[val].size(); j++){
                int element = adj[val][j];
                if (!visited[element]){
                    q.push(element);
                    visited[element] = true;
                }
            }
            ans.push_back(val);
        }
    }
    return ans;
}