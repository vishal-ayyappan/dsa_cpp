#include <bits/stdc++.h>
using namespace std;

//BellMan Ford algo, used for directed graph with cycles (Can identify negative cycles)

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    //You do not have to create adjacency list
    //Create a distance array
    vector<int> distance (V, INT_MAX);
    distance[src] = 0;
    for (int i=0; i<V-1; i++){
        //Iterate through all the edges
        bool updated = false;
        for (auto& item : edges){
            int u = item[0];
            int v = item[1];
            int wt = item[2];
            //If the distance is not updated, do not do the operations
            if (distance[u] != INT_MAX){
                int newWeight = distance[u] + wt;
                if (newWeight < distance[v]){
                    distance[v] = newWeight;
                    updated = true;
                }
            }
        }
        if (!updated) break;
    }
    // To check if it contains negative path cycles
    for (auto& item : edges){
        int u = item[0];
        int v = item[1];
        int wt = item[2];
        //If the distance changes, then it means, there is a negative path cycle. (Should not change)
        if (distance[u] != INT_MAX){
            int newWeight = distance[u] + wt;
            if (newWeight < distance[v]){
                return {-1};
            }
        }
    }
    return distance;
}