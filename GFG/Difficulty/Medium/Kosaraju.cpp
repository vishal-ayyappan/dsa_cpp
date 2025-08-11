#include <bits/stdc++.h>
using namespace std;

//Strongly Connected Components 

//SCC --> Every node can be reached from every other node in the SCC.

void finishTime(vector<vector<int>> &adj, vector<bool>& visited, vector<int>& sorted, int node){
    visited[node] = true;
    for (int item : adj[node]){
        if (!visited[item]){
            finishTime(adj, visited, sorted, item);
        }
    }
    sorted.push_back(node);
}

void getConnections(vector<vector<int>> &rev, vector<bool> &vis, int node, vector<int> &connections){
    vis[node] = true;
    connections.push_back(node);
    for (int& item : rev[node]){
        if (!vis[item]){
            getConnections(rev, vis, item, connections);
        }
    }
}

int kosaraju(vector<vector<int>> &adj) {
    // 0/ Sort the graph according to the finishing time
    int n = adj.size();
    vector<int> sorted;
    vector<bool> visited (n, false);
    for (int i=0; i<n; i++){
        if (!visited[i]){
            finishTime(adj, visited, sorted, i);
        }
    }
    reverse(sorted.begin(), sorted.end());
    // 1/ Reverse the graph
    vector<vector<int>> rev (n);
    for (int i=0; i<n; i++){
        for (int& item : adj[i]){
            rev[item].push_back(i);
        }
    }
    // 2/ Do a DFS on the graph
    vector<bool> vis (n, false);
    vector<vector<int>> scc;
    int count = 0;
    for (int& item : sorted){
        if (!vis[item]){
            vector<int> connections;
            count++;
            getConnections(rev, vis, item, connections);
            scc.push_back(connections);
        }
    }
    return count;
}