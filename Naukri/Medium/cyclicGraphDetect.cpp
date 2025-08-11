#include <bits/stdc++.h>
using namespace std;

//Cycle Detection in Directed Graph

vector<vector<int>> getAdjList(vector <pair<int,int>>& edges, int n){
    vector<vector<int>> adjList (n+1);
    int size = edges.size();
    for (int i=0; i<size; i++){
        int first = edges[i].first;
        int second = edges[i].second;
        adjList[first].push_back(second);
    }
    return adjList;
}

bool isCycle(vector<vector<int>>& adjList, int node, vector<bool>& visited, vector<bool>& pathVisited){
    visited[node] = true;
    pathVisited[node] = true;
    for (int u : adjList[node]){
        if (!visited[u]){
            if (isCycle(adjList, u, visited, pathVisited)) return true;
        }
        else if (pathVisited[u]) return true;
    }
    pathVisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    vector<vector<int>> adjList = getAdjList(edges, n);
    vector<bool> visited (n+1, false);
    vector<bool> pathVisited (n+1, false);
    for (int i=1; i<=n; i++){
        if (!visited[i]){
            if (isCycle(adjList, i, visited, pathVisited)) return 1;
        }
    }
    return 0;
}