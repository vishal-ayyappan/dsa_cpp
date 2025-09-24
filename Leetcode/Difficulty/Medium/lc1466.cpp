#include <bits/stdc++.h>
using namespace std;

//Reorder Routes to Make All Paths Lead to the City Zero

vector<vector<pair<int, int>>> getAdjList(int n, vector<vector<int>>& connections){
    vector<vector<pair<int, int>>> adjList (n);
    int size = connections.size();
    for (int i=0; i<size; i++){
        int u = connections[i][0];
        int v = connections[i][1];
        //Original
        adjList[u].push_back({v, 1});
        //Fake (in the opposite connection)
        adjList[v].push_back({u, 0});
    }
    return adjList;
}

int getDfs(vector<vector<pair<int, int>>>& adjList, int i, vector<bool>& visited){
    visited[i] = true;
    //This network form a tree
    int ans = 0;
    for (auto& item : adjList[i]){
        int u = item.first;
        int isChanged = item.second;
        if (!visited[u]){
            int val = getDfs(adjList, u, visited);
            ans += val;
            ans += isChanged;
        }
        
    }
    return ans;
}

int minReorder(int n, vector<vector<int>>& connections) {
    //Get adjacency list
    vector<vector<pair<int, int>>> adjList = getAdjList(n, connections);
    //Do a DFS traversal starting from 0
    vector<bool> visited (n, false);
    int result = getDfs(adjList, 0, visited);
    return result;
}