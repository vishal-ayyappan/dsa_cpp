#include <bits/stdc++.h>
using namespace std;

bool hasallEl(int V, vector<int> adj[], int node){
    vector<bool> visited (V, false);
    int count = 0;
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while (!q.empty()){
        int n = q.size();
        for (int i=0; i<n; i++){
            int val = q.front();
            q.pop();
            for (int j=0; j<adj[val].size(); j++){
                int element = adj[val][j];
                if (!visited[element]){
                    q.push(element);
                    visited[element] = true;
                }
            }
            count++;
        }
    }
    return (count == V);
}

int findMotherVertex(int V, vector<int> adj[]) {
    int ans = -1;
    for (int i=0; i<V; i++){
        if(hasallEl(V, adj, i)){
            ans = i;
            break;
        }
    }
    return ans;
}