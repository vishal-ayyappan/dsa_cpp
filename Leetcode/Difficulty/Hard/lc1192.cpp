#include <bits/stdc++.h>
using namespace std;

//Critical Connections in a Network

vector<vector<int>> getAdjList(int n, vector<vector<int>>& connections){
    vector<vector<int>> adjList (n);
    int size = connections.size();
    for (int i=0; i<size; i++){
        int u = connections[i][0];
        int v = connections[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    return adjList;
}


void getConnections(vector<vector<int>>& adjList, int& time, vector<int>& tin, vector<int>& low, vector<bool>& visited, 
    vector<vector<int>>& ans, int node, int parent){
        visited[node] = true;
        tin[node] = time;
        low[node] = time;
        time++;
        for (int& item : adjList[node]){
            if (item == parent) continue;
            //Cannot be a bridge, but the low[item] might change, as it sees the adjacent nodes
            if (visited[item]){
                low[node] = min(low[item], low[node]);
            }
            //Can be a bridge
            else{
                getConnections(adjList, time, tin, low, visited, ans, item, node);
                low[node] = min(low[node], low[item]);
                if (tin[node] < low[item]){
                    ans.push_back({node, item});
                }
            }
        }
    }

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    //Get the adjacency list
    vector<vector<int>> adjList = getAdjList(n, connections);
    // Create a tin and low
    // tin[i] --> Time of insertion of i
    // low[i] --> min time of insertion if the adjacent nodes, except parent
    vector<int> tin(n);
    vector<int> low(n);
    vector<bool> visited (n, false);
    vector<vector<int>> ans;
    int time = 0;
    getConnections(adjList, time, tin, low, visited, ans, 0, -1);
    return ans;
} 