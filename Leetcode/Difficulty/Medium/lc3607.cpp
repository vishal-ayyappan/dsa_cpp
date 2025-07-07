#include <bits/stdc++.h>
using namespace std;

//Approach 1


vector<vector<int>> getAdjList(vector<vector<int>>& connections, int c){
    vector<vector<int>> adjList (c+1);
    int n = connections.size();
    for (int i = 0; i<n; i++){
        int first = connections[i][0];
        int second = connections[i][1];
        adjList[first].push_back(second);
        adjList[second].push_back(first);
    }
    return adjList;
}



int checkConnections(vector<vector<int>>& adjList, int element, vector<bool>& gridStatus){
    int val = INT_MAX;
    int n = gridStatus.size();
    vector<bool> visited (n, false);
    queue<int> q;
    q.push(element);
    visited[element] = true;
    while (!q.empty()){
        int node = q.front();
        q.pop();
        if (gridStatus[node] == true) {
            val = min(val, node);
        }
        for (int i=0; i<adjList[node].size(); i++){
            int neighbours = adjList[node][i];
            if (!visited[neighbours]){
                q.push(neighbours);
                visited[neighbours] = true;
            }
        }
    }
    if (val == INT_MAX) return -1;
    return val;
}

vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
    //Make all the power stations on
    vector<bool> gridStatus (c+1, true); 
    //Get the adjacency list for each node
    vector<vector<int>> adjList = getAdjList(connections, c);
    //Check for each query
    vector<int> ans;
    int n = queries.size();
    for (int i=0; i<n; i++){
        //If query is 1 (Return the node if it is on)
        if (queries[i][0] == 1){
            int node = queries[i][1];
            if (gridStatus[node] == true) ans.push_back(node);
            else ans.push_back(checkConnections(adjList, node, gridStatus));  
        }
        else{
            gridStatus[queries[i][1]] = false;
        }
    }
    return ans;
}