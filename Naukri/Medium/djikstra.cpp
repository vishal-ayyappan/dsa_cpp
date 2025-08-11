#include <bits/stdc++.h>
using namespace std;


vector<vector<pair<int,int>>> getAdjList(vector<vector<int>> &vec, int vertices){
    vector<vector<pair<int,int>>> adjList (vertices);
    int n = vec.size();
    for (int i=0; i<n; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int wt = vec[i][2];
        adjList[u].push_back({v, wt});
        adjList[v].push_back({u, wt});
    }
    return adjList;
}

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // 0/ Get the adjacency list
    vector<vector<pair<int,int>>> adjList = getAdjList(vec, vertices);
    // 1/ Use a priority queue to store the {distance, node}, we need the minimum distance, that is the reason why we use pq
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //For min heap
    // 2/ Store the distance and the source in the queue, according to some conditions
    vector<int> distance (vertices, INT_MAX);
    //Push the source node along with the distance
    distance[source] = 0;
    pq.push({distance[source], source});
    while (!pq.empty()){
        auto item = pq.top();
        int node = item.second;
        int weight = item.first;
        pq.pop();
        for (auto& val : adjList[node]){
            int conn_node = val.first;
            int conn_weight = val.second;
            int new_dist_to_conn_node_from_src = weight + conn_weight;
            if (new_dist_to_conn_node_from_src < distance[conn_node]){
                distance[conn_node] = new_dist_to_conn_node_from_src;
                pq.push({new_dist_to_conn_node_from_src, conn_node});
            }
        }
    }
    return distance;
}