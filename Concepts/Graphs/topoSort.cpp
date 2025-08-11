#include <bits/stdc++.h>
using namespace std;

//Can only be done on DAG

//Topological sort using DFS
vector<vector<int>> getAdjList(int V, vector<vector<int>>& edges){
    vector<vector<int>> adjList(V);
    int n = edges.size();
    for (int i=0; i<n; i++){
        int first = edges[i][0];
        int second = edges[i][1];
        adjList[first].push_back(second);
    }
    return adjList;
}

//Given a DAG
void getSorted(vector<vector<int>>& adjList, int node, vector<bool>& visited, vector<int>& sorted){
    visited[node] = true;
    for (int u : adjList[node]){
        if (!visited[u]){
            getSorted(adjList, u, visited, sorted);
        }
    }
    sorted.push_back(node);
}

vector<int> topoSort(int V, vector<vector<int>>& edges) {
    //Create an adjacency list
    vector<vector<int>> adjList = getAdjList(V, edges);
    vector<bool> visited (V, false);
    vector<int> sorted;
    for (int i=0; i<V; i++){
        if (!visited[i]){
            getSorted(adjList, i, visited, sorted);
        }
    }
    reverse(sorted.begin(), sorted.end());
    return sorted;
}




//Topological Sort using BFS (Kahn's Algorithm)
vector<vector<int>> getAdjList(int V, vector<vector<int>>& edges){
    vector<vector<int>> adjList(V);
    int n = edges.size();
    for (int i=0; i<n; i++){
        int first = edges[i][0];
        int second = edges[i][1];
        adjList[first].push_back(second);
    }
    return adjList;
}

vector<int> getIndegree(int V, vector<vector<int>>& edges){
    vector<int> inDegree (V);
    int n = edges.size();
    for (int i=0; i<n; i++){
        int second = edges[i][1];
        inDegree[second]++;
    }
    return inDegree;
}

vector<int> getSorted_bfs(vector<vector<int>>& adjList, vector<int>& inDegree){
    vector<int> sorted;
    //Insert all the nodes with indgree 0 in the queue
    queue<int> q;
    int size = inDegree.size();
    for (int i=0; i<size; i++){
        if (inDegree[i] == 0){
            q.push(i);
        }
    }
    while (!q.empty()){
        int node = q.front();
        q.pop();
        sorted.push_back(node);
        for (int u : adjList[node]){
            inDegree[u]--;
            if (inDegree[u] == 0){
                q.push(u);
            }
        }
    }
    return sorted;
}

//Given DAG (there must be atleast one node with indegree 0)
vector<int> topoSort(int V, vector<vector<int>>& edges) {
    //Create an adjacency list
    vector<vector<int>> adjList = getAdjList(V, edges);
    vector<int> inDegree = getIndegree(V, edges);
    vector<int> temp = getSorted_bfs(adjList, inDegree);
    if (temp.size() == V) return temp;
    return {-1};
}
