#include <bits/stdc++.h>
using namespace std;

//Number of provinces (Doing DFS on adjacency matrix)

void getDfs(vector<vector<int>>& roads, int idx, vector<bool>& visited){
    visited[idx] = true;
    //idx represents the roads of the cities
    // roads[idx][i] represents whether there is a road or not
    for (int i=0; i<roads.size(); i++){
        if (!visited[i] && roads[idx][i] == 1){
            getDfs(roads, i, visited);
        }
    }
}

int findNumOfProvinces(vector<vector<int>>& roads, int n) {
    vector<bool> visited (n, false);
    int count = 0;
    for (int i=0; i<n; i++){
        if (!visited[i]){
            getDfs(roads, i, visited);
            count++;
        }
    }
    return count;
}