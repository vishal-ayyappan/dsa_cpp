#include <bits/stdc++.h>
using namespace std;

//Graph Valid Tree
vector<vector<int>> getAdjList(vector<vector<int>> edges, int n){
    int size = edges.size();
    vector<vector<int>> adjList (n);
    for (int i=0; i<size; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    return adjList;
}


bool checkValid(vector<vector<int>>& adjList){
    //BFS to check the presence of the cycle
    int n = adjList.size();
    queue<pair<int, int>> q;
    vector<bool> visited (n, false);
    int parent = -1;
    q.push({0, -1});
    visited[0] = true;
    while (!q.empty()){
        auto item = q.front(); q.pop();
        int node = item.first;
        int parent = item.second;
        for (int& u : adjList[node]){
            if (!visited[u]){
                visited[u] = true;
                q.push({u, node});
            }
            //If it is visited and if it aint parent, then cycle exists
            else if (u != parent) return false;
        }
    }
    for (int i=0; i<n; i++) if (!visited[i]) return false;
    return true;
}

bool checkgraph(vector<vector<int>> edges, int n, int m){
    // write your code here
    //Get the adjacency list
    vector<vector<int>> adjList = getAdjList(edges, n);
    //Check for a cycle
    return checkValid(adjList);   
}