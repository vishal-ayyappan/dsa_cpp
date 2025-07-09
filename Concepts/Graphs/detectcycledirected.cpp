#include <bits/stdc++.h>
using namespace std;

/*
Use a visited and a pathVisited array
When you go back, remove the pathVisited[i]
*/

vector<vector<int>> getAdjList(int V, vector<vector<int>> &edges){
    vector<vector<int>> adjList (V);
    for (int i=0; i<edges.size(); i++){
        int first = edges[i][0];
        int second = edges[i][1];
        adjList[first].push_back(second);
    }
    return adjList;
}

bool dfs(vector<vector<int>> &adjList, vector<bool>& visited, vector<bool>& pathVisited, int node){
    visited[node] = true;
    pathVisited[node] = true;
    for (int i=0; i<adjList[node].size(); i++){
        int element = adjList[node][i];
        if (!visited[element]){
            if(dfs(adjList, visited, pathVisited, element)) return true;
        }
        else if (pathVisited[element]) return true;  
    }
    pathVisited[node] = false;
    return false;
}

bool isCyclic(int V, vector<vector<int>> &edges) {
    vector<vector<int>> adjList = getAdjList(V, edges);
    vector<bool> visited (V, false);
    vector<bool> pathVisited (V, false);   
    for (int i=0; i<V; i++){
        if (!visited[i]){
            if (dfs(adjList, visited, pathVisited, i)) return true;
        }
    }
    return false;
}