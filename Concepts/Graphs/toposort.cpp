#include <bits/stdc++.h>
using namespace std;


/*
0/ Build Adjacency List
1/ Initialize visited + result array
2/ DFS on unvisited nodes
3/ Post-order push to result
4/ Reverse result
*/

vector<vector<int>> getAdjList(int V, vector<vector<int>>& edges){
    vector<vector<int>> adjList (V);
    for (int i=0; i<edges.size(); i++){
        int first = edges[i][0];
        int second = edges[i][1];
        adjList[first].push_back(second);
    }
    return adjList;
}

void dfs(vector<vector<int>>& adjList, int node, vector<int>& sorted, vector<bool>& visited){
    visited[node] = true;
    for (int i=0; i<adjList[node].size(); i++){
        int element = adjList[node][i];
        if (!visited[element]){
            dfs(adjList, element, sorted, visited);
        }
    }
    sorted.push_back(node);
}

vector<int> topoSort(int V, vector<vector<int>>& edges) {
    //Get the adjacency list
    vector<vector<int>> adjList = getAdjList(V, edges);
    vector<int> sorted;
    vector<bool> visited (V, false);
    for (int i=0; i<V; i++){
        if (!visited[i]){
            dfs(adjList, i, sorted, visited);
        }
    }
    reverse(sorted.begin(), sorted.end());
    return sorted;
}

//TC - O(V+E)
//SC = O(V+E)

//Khan's Algorithm 
//Topological Sort using BFS
vector<vector<int>> getAdjList(vector<vector<int>> &edges, int v){
    vector<vector<int>> adjList (v);
    for (int i=0; i<edges.size(); i++){
        int first = edges[i][0];
        int second = edges[i][1];
        adjList[first].push_back(second);
    }
    return adjList;
}

vector<int> getIndegree(vector<vector<int>> &edges, int v){
    vector<int> inDegree (v);
    for (int i=0; i<edges.size(); i++){
        int second = edges[i][1];
        inDegree[second]++;
    }
    return inDegree;
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> ans;
    //Get the adjacency List
    vector<vector<int>> adjList = getAdjList(edges, v);
    //Get the indegree of the nodes
    vector<int> inDegree = getIndegree(edges, v);
    //Do a BFS with some modification
    vector<bool> visited (v, false);
    queue<int> q;
    for (int i=0; i<v; i++){
        if (inDegree[i] == 0) q.push(i);
        visited[i] = true;
    }
    while (!q.empty()){
        int val = q.front();
        ans.push_back(val);
        q.pop();
        for (int i=0; i<adjList[val].size(); i++){
            int element = adjList[val][i];
            inDegree[element]--;
            if (inDegree[element] == 0) q.push(element);
        }
    }
    return ans;
}