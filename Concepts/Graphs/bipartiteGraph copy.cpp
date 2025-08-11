#include <bits/stdc++.h>
using namespace std;

//Check Bipartite Graph (If the graph can be colored in such a way that no 2 adjacent nodes have the same color
// then that graph is bipartite)

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

bool checkBipartite(vector<vector<int>>& adjList, int node, vector<int>& color){
    queue<int> q;
    q.push(node);
    color[node] = 0;
    while (!q.empty()){
        int node_ = q.front();
        q.pop();
        for (int newNode : adjList[node_]){
            if (color[newNode] == -1){
                color[newNode] = 1 - color[node_];
                q.push(newNode);
            }
            else if (color[newNode] == color[node_]) return false;
        }
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
            if (!checkBipartite(adjList, i, color)) return false;
        }
        
    }
    return true;
}