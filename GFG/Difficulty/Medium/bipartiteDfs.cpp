#include <bits/stdc++.h>
using namespace std;

//Bipartite graph using dfs

vector<vector<int>> getAdjList(vector<vector<int>>& graph, int vertices){
    int n = graph.size();
    vector<vector<int>> adjList (vertices);
    for (int i=0; i<n; i++){
        int first = graph[i][0];
        int second = graph[i][1];
        adjList[first].push_back(second);
        adjList[second].push_back(first);
    }
    return adjList;
}

bool checkBipartite(vector<vector<int>>& adjList, int node, vector<int>& color, int prev_color){
    color[node] = 1 - prev_color;
    for (int u : adjList[node]){
        if (color[u] == -1){
            if (!checkBipartite(adjList, u, color, color[node])) return false;
        }
        // If the adjacent node has the color, then it is not bipartite.
        else if (color[u] == color[node]) return false;
    }
    return true;
}

bool isBipartite(int V, vector<vector<int>> &edges){;
    //Create the adjacency list
    vector<vector<int>> adjList = getAdjList(edges, V);
    //Create the color array
    vector<int> color (V, -1);
    for (int i=0; i<V; i++){
        if (color[i] == -1){
            if (!checkBipartite(adjList, i, color, 1)) return false;
        } 
    }
    return true;
}