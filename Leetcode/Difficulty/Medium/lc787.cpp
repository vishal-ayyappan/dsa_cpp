#include <bits/stdc++.h>
using namespace std;

//You do Dijkstra with normal queue, instead of priority as we deal with stops here
// stops is our first priority, and it keeps on increasing monotonucally, that is why we do not use priority queue.

vector<vector<pair<int, int>>> getAdjList(int n, vector<vector<int>>& flights){
    vector<vector<pair<int, int>>> adjList (n);
    int size = flights.size();
    for (int i=0; i<size; i++){
        int u = flights[i][0];
        int v = flights[i][1];
        int wt = flights[i][2];
        adjList[u].push_back({v, wt});
    }
    return adjList;
}

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    //Cannot use topo sort as the graph can be cyclic

    // 0/ Get the adjacency list
    vector<vector<pair<int, int>>> adjList = getAdjList(n, flights);
    // 1/ Do a Djikstra to get the shortest path
    queue<pair<int, int>> q; // (No priority queue) queue, storing {distance, node}
    vector<int> distance (n, INT_MAX);
    distance[src] = 0;
    q.push({distance[src], src});
    int count = 0;
    while (!q.empty()){
        int q_size = q.size();
        for (int i=0; i<q_size; i++){
            auto item = q.front();
            q.pop();
            int dist = item.first;
            int node = item.second;
            if (count > k) break;
            for (auto& info : adjList[node]){
                int conn_node = info.first;
                int conn_weight = info.second;
                int newWeight = conn_weight + dist;
                if (newWeight < distance[conn_node]){
                    distance[conn_node] = newWeight;
                    q.push({distance[conn_node], conn_node});
                }
            }
        }
        count++;
    }
    if (distance[dst] == INT_MAX) return -1;
    return distance[dst];
}