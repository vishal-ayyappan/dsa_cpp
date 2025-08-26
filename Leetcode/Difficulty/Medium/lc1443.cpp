#include <bits/stdc++.h>
using namespace std;

//Minimum Time to Collect All Apples in a Tree (This is done using DFS) 
// Kinda different from the usual patterns

vector<vector<int>> getAdjList(int n, vector<vector<int>>& edges){
    vector<vector<int>> adjList (n);
    int size = edges.size();
    for (int i=0; i<size; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    return adjList;
}

int getMinTime(vector<vector<int>>& adjList, vector<bool>& hasApple, int node, int parent){
    //Initialize its time as 0
    int time = 0;
    for (int& child : adjList[node]){
        if (child == parent) continue;
        int time_from_child = getMinTime(adjList, hasApple, child, node);
        if (time_from_child > 0 || hasApple[child]){
            time += time_from_child + 2;
        }
    }
    return time;
}

int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    //Get adjacency list
    vector<vector<int>> adjList = getAdjList(n, edges);
    //Do a DFS starting from node 0W
    return getMinTime(adjList, hasApple, 0, -1);
}