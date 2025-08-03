#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
    vector<vector<int>> adjMatrix (V, vector<int> (V, 0));
    int n = edges.size();
    for (int i=0; i<n; i++){
        int node1 = edges[i].first;
        int node2 = edges[i].second;
        adjMatrix[node1][node2] = 1;
        adjMatrix[node2][node1] = 1;
    }
    return adjMatrix;
}

//Adjacency matrix take a lot of space and is not generally used to represent graphs

//Adjacency matrix

vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
    vector<vector<int>> adjList (V);
    int n = edges.size();
    for (int i=0; i<n; i++){
        int node1 = edges[i].first;
        int node2 = edges[i].second;
        adjList[node1].push_back(node2);
        adjList[node2].push_back(node1);
    }
    return adjList;
}