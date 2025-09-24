#include <bits/stdc++.h>
using namespace std;

//Find Closest Node to Given Two Nodes

vector<vector<int>> getAdjList(vector<int>& edges){
    int n = edges.size();
    vector<vector<int>> adjList (n);
    for (int i=0; i<n; i++){
        int u = i;
        int v = edges[i];
        if (v == -1) continue;
        adjList[u].push_back(v);
    }
    return adjList;
}

void getDistance(vector<vector<int>>& adjList, int node, int distance, vector<int>& distance_node){
    distance_node[node] = distance;
    //Only has atmost 1 outgoing edge
    if (adjList[node].size() != 0){
        int u = adjList[node][0];
        if (distance_node[u] == -1){
            getDistance(adjList, u, distance+1, distance_node);
        }   
    }
}

int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    //Do a DFS starting from node1 and node2
    //Get the adjacency list
    int n = edges.size();
    vector<vector<int>> adjList = getAdjList(edges);
    //DFS on node 1
    vector<int> distance_node1 (n, -1);
    getDistance(adjList, node1, 0, distance_node1);
    //DFS on node2
    vector<int> distance_node2 (n, -1);
    getDistance(adjList, node2, 0, distance_node2);
    //Go through the distance of each
    int mini = INT_MAX;
    int ans = -1;
    for (int i=0; i<n; i++){
        int distance_from_node1 = distance_node1[i];
        int distance_from_node2 = distance_node2[i];
        if (distance_from_node1 == -1 || distance_from_node2 == -1) continue;
        int maxDistance = max(distance_from_node1, distance_from_node2);
        if (maxDistance < mini){
            mini = maxDistance;
            ans = i;
        }
    }
    return ans;
}