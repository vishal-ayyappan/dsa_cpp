#include<bits/stdc++.h>
using namespace std;

//1/ Get Adjacency List
//2/ Traverse through each node and if it is not visited, do a traversal starting from
//that node.

vector<vector<int>> AdjacencyList(int V, vector<vector<int>>& edges){
    vector<vector<int>> ans (V);
    for (int i=0; i<edges.size(); i++){
        ans[edges[i][0]].push_back(edges[i][1]);
        ans[edges[i][1]].push_back(edges[i][0]);
    }
    return ans;
}

vector<int> getBfs(vector<vector<int>>& adjList, int node, vector<bool>& visited){
    //Do BFS with the node as the starting point
    vector<int> ans;
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while (!q.empty()){
        int n = q.size();
        for (int i=0; i<n; i++){
            int val = q.front();
            q.pop();
            for (int j=0; j<adjList[val].size(); j++){
                int element = adjList[val][j];
                if (!visited[element]){
                    q.push(element);
                    visited[element] = true;
                }
            }
            ans.push_back(val);
        }
    }
    return ans;
}

vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
    vector<vector<int>> ans;
    //0 based indexing
    //Create an adjacency list
    vector<vector<int>> adjList = AdjacencyList(V, edges);
    vector<bool> visited (V, false);
    for (int i=0; i<V; i++){
        if (!visited[i]){
            //get the traversal
            vector<int> bfs = getBfs(adjList, i, visited);
            ans.push_back(bfs);
        }
    }
    return ans;
}