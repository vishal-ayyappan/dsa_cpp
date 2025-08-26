#include <bits/stdc++.h>
using namespace std;

// Possible Bipartition

bool isBipartite(vector<vector<int>>& adjList, int node, vector<int>& color){
    //We would do a BFS
    queue<int> q;
    q.push(node);
    color[node] = 0;
    while (!q.empty()){
        int node = q.front();
        q.pop();
        for (int& u : adjList[node]){
            //If it is not visited
            if (color[u] == -1){
                color[u] = 1 - color[node];
                q.push(u);
            }
            else if (color[node] == color[u]) return false;
        }
    }
    return true;
}

vector<vector<int>> getAdjList (int n, vector<vector<int>>& dislikes){
    vector<vector<int>> adjList (n+1);
    int size = dislikes.size();
    for (int i=0; i<size; i++){
        int u = dislikes[i][0];
        int v = dislikes[i][1];
        // u does not like v, if u does not like v, v does not like u as well.
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    return adjList;
}

bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    //You just have to check bipartideness
    //Find the adjacency list
    vector<vector<int>> adjList = getAdjList(n, dislikes);
    //Can do a BFS/DFS
    vector<int> color (n+1, -1);
    //There could be disconnected components
    for (int i=0; i<n; i++){
        //If the node is not visited
        if (color[i] == -1){
            if (!isBipartite(adjList, i, color)) return false;
        }
    }
    return true;
}