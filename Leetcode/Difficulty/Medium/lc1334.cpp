#include <bits/stdc++.h>
using namespace std;

//Find the City With the Smallest Number of Neighbors at a Threshold Distance

vector<vector<int>> getDistance(int n, vector<vector<int>>& edges){
    vector<vector<int>> distance (n, vector<int> (n, INT_MAX));
    for (int i=0; i<n; i++) distance[i][i] = 0;
    for (auto& item : edges){
        int u = item[0];
        int v = item[1];
        int wt = item[2];
        distance[u][v] = wt;
        distance[v][u] = wt;
    }
    return distance;
}

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    //Figure out the shortest distance for each node to each other node
    //Create the distance matrix
    vector<vector<int>> distance = getDistance(n, edges);
    //Now check the shortes distance via each path
    for (int via=0; via<n; via++){
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (via == i || via == j) continue;
                //If the path exist
                if (distance[i][via] != INT_MAX && distance[via][j] != INT_MAX){
                    int newWeight = distance[i][via] + distance[via][j];
                    distance[i][j] = min(newWeight, distance[i][j]);
                }
            }
        }
    }
    int mini = INT_MAX;
    int ans = -1;
    for (int i=0; i<n; i++){
        int count = 0;
        for (int j=0; j<n; j++){
            if (i == j) continue;
            if (distance[i][j] <= distanceThreshold) count++;
        }
        if (count <= mini){
            mini = count;
            ans = i;
        }
    }
    return ans;
}