#include <bits/stdc++.h>
using namespace std;

//Number of Ways to Arrive at Destination

vector<vector<pair<int, int>>> getAdjList(int n, vector<vector<int>>& roads){
    vector<vector<pair<int, int>>> adjList (n);
    int size = roads.size();
    for (int i=0; i<size; i++){
        int u = roads[i][0];
        int v = roads[i][1];
        int wt = roads[i][2];
        //Bidirectional roads (so unweighted graphs)
        adjList[u].push_back({v, wt});
        adjList[v].push_back({u, wt});
    }
    return adjList;
}

const int MOD = 1e9 + 7;

int countPaths(int n, vector<vector<int>>& roads) {
    // Create the adjacency list
    vector<vector<pair<int, int>>> adjList = getAdjList(n, roads);
    // You have to count the no of paths to get from 0 to n-1 in the shortest amount of time
    // 1/ To get the minimum time, to get from 0 to n-1, we use Dijkstra
    // I guess you have to push it to the queue, whenever the new_dist <= distance[conn_node] //This is wrong

    //Create a ways array, that tells you the number of ways, that you can get to a node in the shortest distance.
    vector<long long> distance (n, LLONG_MAX);
    vector<int> ways (n, 0);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq; //Min heap
    distance[0] = 0;
    ways[0] = 1;
    pq.push({distance[0], 0});
    while (!pq.empty()){
        auto item = pq.top();
        pq.pop();
        long long dist = item.first;
        int node = item.second;
        for (auto& info : adjList[node]){
            int conn_node = info.first;
            int conn_weight = info.second;
            long long new_distance = dist + conn_weight;
            if (new_distance < distance[conn_node]){
                distance[conn_node] = new_distance;
                pq.push({distance[conn_node], conn_node});
                //When you update it, you just take the no of ways, not add them
                ways[conn_node] = ways[node];
            }
            else if (new_distance == distance[conn_node]){
                ways[conn_node] = (ways[conn_node] + ways[node])%MOD;
            }
        }
    }
    return ways[n-1];
}