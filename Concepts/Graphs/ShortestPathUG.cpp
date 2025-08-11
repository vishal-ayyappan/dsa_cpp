#include <bits/stdc++.h>
using namespace std;

//THis is for weighted undirected graphs (Use parent array)

vector<vector<pair<int, int>>> getAdjList(vector<pair<int,int>>& edges, int n){
    vector<vector<pair<int, int>>> adjList(n+1);
    int size = edges.size();
    for (int i=0; i<size; i++){
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].push_back({v, 1});
        adjList[v].push_back({u, 1});
    }
    return adjList;
}

vector<int> shortestPath(vector<pair<int,int>> edges , int n , int m, int s , int t){
    // 0/ Get the adjacency list
    vector<vector<pair<int, int>>> adjList = getAdjList(edges, n);
    // 1/ Do the Djikstra Algo
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //Min Heap
    vector<int> distance (n+1, INT_MAX);
    vector<int> parent (n+1);
    for (int i=0; i<=n; i++) parent[i] = i;
    distance[s] = 0;
    //Store the distance and the node in the min heap
    pq.push({distance[s], s}); 
    while (!pq.empty()){
        auto item = pq.top();
        pq.pop();
        int node = item.second;
        int weight = item.first; //Distance from that node to the source node.
        for (auto& val : adjList[node]){
            int conn_node = val.first;
            int conn_weight = val.second;
            int newWeight = weight + conn_weight;
            if (newWeight < distance[conn_node]){
                distance[conn_node] = newWeight;
                pq.push({distance[conn_node], conn_node});
                parent[conn_node] = node;
            }
        }
    }
    vector<int> ans;
    int node = t;
    if (distance[node] == INT_MAX) return {};
    while (node != parent[node]){
        ans.push_back(node);
        node = parent[node];
    }
    if (node == parent[node]) ans.push_back(node);
    else return {};
    reverse(ans.begin(), ans.end());
    return ans;
}
