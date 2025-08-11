#include <bits/stdc++.h>
using namespace std;

//Shortest Path in Undirected Graph

vector<int> getDistance(vector<vector<int>>& adj, vector<bool>& visited, int src){
    int n = adj.size();
    vector<int> distance (n, -1);
    queue<int> q;
    q.push(src);
    visited[src] = true;
    int count = 0;
    while (!q.empty()){
        int size = q.size();
        for (int i=0; i<size; i++){
            int node = q.front();
            q.pop();
            distance[node] = count;
            for (int u : adj[node]){
                if (!visited[u]){
                    q.push(u);
                    visited[u] = true;
                }
            }
        }
        count++;
    }
    return distance;
}

vector<int> shortestPath(vector<vector<int>>& adj, int src) {
    //Do a BFS/DFS on the source
    int n = adj.size();
    vector<bool> visited (n, false);
    vector<int> distance = getDistance(adj, visited, src);
    return distance;
}