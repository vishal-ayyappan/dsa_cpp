#include <bits/stdc++.h>
using namespace std;

//Euler Path and circuit

void getDfs(vector<int> adj[], int node, vector<bool>& visited){
    visited[node] = true;
    for (int u : adj[node]){
        if (!visited[u]){
            getDfs(adj, u, visited);
        }
    }
}

int isEulerCircuit(int V, vector<int> adj[]) {
    //Check if the graph is connected, if it is not connected, check if the not connected nodes are 0, if not it is non eulerian
    vector<int> degrees (V);
    //Get the Degrees
    for (int i=0; i<V; i++){
        int deg = adj[i].size();
        degrees[i] = deg;
    }
    vector<bool> visited (V, false);
    int countConnected = 0;
    int i = 0;
    while (i<V){
        if (!visited[i]){
            countConnected++;
            if (countConnected > 1) break;
            getDfs(adj, i, visited);
        }
        i++;
    }
    if (countConnected == 2){
        //Check if the non visited nodes have zero degrees
        for (int i=0; i<V; i++){
            if (!visited[i]){
                //Non Eulerian
                if (degrees[i] != 0) return 0;
            }
        }
    }
    //Check the oddDegrees
    int count = 0;
    for (int i=0; i<V; i++){
        if (degrees[i]%2 == 1) count++;
    }
    if (count > 2) return 0;
    if (count == 2) return 1;
    return 2;
}