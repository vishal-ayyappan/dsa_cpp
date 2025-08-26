#include <bits/stdc++.h>
using namespace std;

//Find if Path Exists in Graph
vector<vector<int>> getAdjList(int n, vector<vector<int>>& edges){
    vector<vector<int>> adjList (n);
    int size = edges.size();
    for (int i=0; i<size; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    return adjList;
}

bool getDfs(vector<vector<int>>& adjList, int node, int destination, vector<bool>& visited){
    if (node == destination) return true;
    visited[node] = true;
    for (int& u : adjList[node]){
        if (!visited[u]){
            if (getDfs(adjList, u, destination, visited)) return true;
        }
    }
    return false;
}

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    //Just do a Plain DFS
    //Get the adjacency list
    vector<vector<int>> adjList = getAdjList(n, edges);
    vector<bool> visited (n, false);
    return getDfs(adjList, source, destination, visited);
}