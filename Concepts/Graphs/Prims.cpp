#include <bits/stdc++.h>
using namespace std;

//Prim's Algorithm

vector<vector<pair<int, int>>> getAdjList(int V, vector<vector<int>>& edges){
    vector<vector<pair<int, int>>> adjList (V);
    int n = edges.size();
    for (int i=0; i<n; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adjList[u].push_back({v, wt});
        adjList[v].push_back({u, wt});
    }
    return adjList;
}

int spanningTree(int V, vector<vector<int>>& edges) {
    //Get the adjacency list
    vector<vector<pair<int, int>>> adjList = getAdjList(V, edges);
    // Keep the visited array
    vector<bool> visited (V, false);
    vector<vector<int>> mst;
    //Priority queue to store the distance, and the {node, parent}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int sum = 0;
    pq.push({0, {0, -1}});
    while (!pq.empty()){
        auto item = pq.top();
        pq.pop();
        int wt = item.first;
        int node = item.second.first;
        int parent = item.second.second;
        if (visited[node]) continue;
        if (parent != -1) mst.push_back({parent, node});
        sum += wt;
        visited[node] = true;
        for (auto& info : adjList[node]){
            int conn_node = info.first;
            int conn_weight = info.second;
            if (!visited[conn_node]){
                pq.push({conn_weight, {conn_node, node}});
            }
        }
    }
    return sum;
}