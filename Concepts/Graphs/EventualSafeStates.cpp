#include <bits/stdc++.h>
using namespace std;

//Find Eventual Safe states

//Usin DFS
bool isCyclic(vector<int> adj[], vector<bool>& visited, int node, vector<bool>& pathVisited, vector<bool>& check){
    visited[node] = true;
    pathVisited[node] = true;
    for (int u : adj[node]){
        if (!visited[u]){
            if (isCyclic(adj, visited, u, pathVisited, check)) return true;
        }
        else if (pathVisited[u]) return true; 
    }
    //When the node does not form a cycle, you keep the pathVisited to false (it is one of our answers)
    check[node] = true;
    pathVisited[node] = false;
    return false;
}

vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    //Create a vsited array
    vector<bool> visited (V, false);
    vector<bool> check (V);
    vector<bool> pathVisited (V, false);
    for (int i=0; i<V; i++){
        if (!visited[i]){
            isCyclic(adj, visited, i, pathVisited, check);
        }
    }
    vector<int> ans;
    for (int i=0; i<V; i++){
        if (check[i]){
            ans.push_back(i);
        }
    }
    return ans;
}


