#include <bits/stdc++.h>
using namespace std;


//1 based indexing

//Using DFS
bool isCyclic(vector<vector<int>>& adjList, int node, vector<bool>& visited, int parent){
    visited[node] = true;
    int size = adjList[node].size();
    for (int i=0; i<size; i++){
        int num = adjList[node][i];
        if (!visited[num]){
           if(isCyclic(adjList, num, visited, node)) return true;
        }
        //If it is visited and its not a parent, then it is cyclic
        else if (num != parent) return true;
    }
    return false;
}

//Using BFS
bool isCyclic(vector<vector<int>>& adjList, int node, vector<bool>& visited, int parent){
    queue<pair<int, int>> q;
    visited[node] = true;
    q.push({node, parent});
    while (!q.empty()){
        int size = q.size();
        for (int i=0; i<size; i++){
            int temp_node = q.front().first;
            int temp_parent = q.front().second;
            q.pop();
            int n = adjList[temp_node].size();
            for (int j=0; j<n; j++){
                int newNode = adjList[temp_node][j];
                if (!visited[newNode]){
                    visited[newNode] = true;
                    q.push({newNode, temp_node});
                }
                //If it is the parent
                else if (newNode != temp_parent) return true;
            }
        }
    }
    return false;
}


vector<vector<int>> getAdjList(vector<vector<int>>& edges, int n){
    vector<vector<int>> adjList (n+1);
    int size = edges.size();
    for (int i=0; i<size; i++){
        int first = edges[i][0];
        int second = edges[i][1];
        adjList[first].push_back(second);
        adjList[second].push_back(first);
    }
    return adjList;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m){
    // 0/ Get Adjacency list
    vector<vector<int>> adjList = getAdjList(edges, n);
    vector<bool> visited (n+1, false);
    for (int i=1; i<=n; i++){
        if (!visited[i]){
            if (isCyclic(adjList, i, visited, 0)) return "Yes";
        }
    }
    return "No";
}
