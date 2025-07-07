#include <bits/stdc++.h>
using namespace std;

//Count the number of connected components
//Convert the adjacency matrix to adjacency list and then do any traversal
vector<vector<int>> AdjacencyList(vector<vector<int>>& isConnected){
    int n = isConnected.size();
    vector<vector<int>> adjList (n+1);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (i != j && isConnected[i][j] == 1){
                adjList[i+1].push_back(j+1);
            }
        }
    }
    return adjList;
}

void dfsTraversal(vector<vector<int>>& adjList, int node, vector<bool>& visited){
    visited[node] = true;
    for (int i=0; i<adjList[node].size(); i++){
        int element = adjList[node][i];
        if (!visited[element]){
            dfsTraversal(adjList, element, visited);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    //Get Adjacency List
    vector<vector<int>> adjList = AdjacencyList(isConnected);
    vector<bool> visited (n+1, false);
    int count = 0;
    for (int i=1; i<=n; i++){
        if (!visited[i]){
            count++;
            dfsTraversal(adjList, i, visited);
        }
    }
    return count;
}

//TC - O(N*N) + O(V+2E) + O(V)
//SC - O(2E) + O(V) 


//Optimal (You can do the dfs using the adjacency matrix itself)
void dfsTrav(vector<vector<int>>& isConnected, int node, vector<bool>& visited){
    visited[node] = true;
    for (int i=0; i<isConnected.size(); i++){
        if (isConnected[node][i] == 1 && !visited[i]){
            dfsTrav(isConnected, i, visited);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<bool> visited (n, false);
    int count = 0;
    for (int i=0; i<n; i++){
        if (!visited[i]){
            count++;
            dfsTrav(isConnected, i, visited);
        }
    }
    return count;
}
//TC - O(N*N)
//SC - O(N)
