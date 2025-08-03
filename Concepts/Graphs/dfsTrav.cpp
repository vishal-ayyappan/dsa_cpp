#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> getAdjList(int V, vector<vector<int>> &edges){
    vector<vector<int>> adjList (V);
    int n = edges.size();
    for (int i=0; i<n; i++){
        int first = edges[i][0];
        int second = edges[i][1];
        adjList[first].push_back(second);
        adjList[second].push_back(first);
    }
    return adjList;
}

void getDfs(vector<vector<int>>& adjList, int idx, vector<bool>& visited, vector<int>& temp){
    visited[idx] = true;
    temp.push_back(idx);
    int size = adjList[idx].size();
    for (int i=0; i<size; i++){
        int num = adjList[idx][i];
        if (!visited[num]){
            getDfs(adjList, num, visited, temp);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges){
    vector<vector<int>> ans;
    vector<vector<int>> adjList = getAdjList(V, edges);
    vector<bool> visited (V, false);
    for (int i=0; i<V; i++){
        if (!visited[i]){
            vector<int> temp;
            getDfs(adjList, i, visited, temp);
            ans.push_back(temp);
        }
    }
    return ans;
}