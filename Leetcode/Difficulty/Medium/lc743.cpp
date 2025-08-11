#include <bits/stdc++.h>
using namespace std;

//Network Delay time (1 based indexing)

vector<vector<pair<int, int>>> getAdjList(vector<vector<int>>& times, int n){
    vector<vector<pair<int, int>>> adjList (n+1);
    int size = times.size();
    for (int i=0; i<size; i++){
        int u = times[i][0];
        int v = times[i][1];
        int wt = times[i][2];
        adjList[u].push_back({v, wt});
    }
    return adjList;
}

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    //Create the adjacency list
    vector<vector<pair<int, int>>> adjList = getAdjList(times, n);
    // Do the Dijkstra
    vector<int> time (n+1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    time[k] = 0;
    // distance and node should be stored
    pq.push({time[k], k});
    while (!pq.empty()){
        auto item = pq.top();
        pq.pop();
        int log_time = item.first;
        int log_node = item.second;
        for (auto& info : adjList[log_node]){
            int conn_node = info.first;
            int conn_weight = info.second;
            int new_time = log_time + conn_weight;
            if (new_time < time[conn_node]){
                time[conn_node] = new_time;
                pq.push({time[conn_node], conn_node});
            }
        }
    }
    int maxi = INT_MIN;
    for (int i=1; i<=n; i++){
        maxi = max(maxi, time[i]);
    }
    //If one of the nodes is not visited
    if (maxi == INT_MAX) return -1;
    return maxi;
}