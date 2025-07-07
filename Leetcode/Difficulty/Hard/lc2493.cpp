#include <bits/stdc++.h>
using namespace std;

/*
// Check Bipartideness (The graph might be diconnected, so check for that)
// As the graph might be disconnected, do a bfs on the main function to store all the components
that are connected to each other. 
// Then run bfs on all the components, and get the maximum depth
// Finally, add all the layers (if not disconnected, getBfs func only runs once)
*/

vector<vector<int>> getAdjList(int n, vector<vector<int>>& edges){
    vector<vector<int>> adjList (n+1);
    for (int i=0; i<edges.size(); i++){
        adjList[edges[i][0]].push_back(edges[i][1]);
        adjList[edges[i][1]].push_back(edges[i][0]);
    }
    return adjList;
}

bool checkIfBipartide(vector<vector<int>>& adjList, vector<int>& color, int node){
    //Do a BFS Bipartide check
    queue<int> q;
    q.push(node);
    color[node] = 0;
    while (!q.empty()){
        int size = q.size();
        for (int i=0; i<size; i++){
            int val = q.front();
            q.pop();
            for (int j=0; j<adjList[val].size(); j++){
                int element = adjList[val][j];
                if (color[element] == -1){
                    q.push(element);
                    if (color[val] == 1) color[element] = 0;
                    else color[element] = 1;
                }
                else if (color[val] == color[element]) return false;
            }
        }
    }
    return true;
}

bool isBipartide(int n, vector<vector<int>>& adjList){
    vector<int> color (n+1,-1); 
    for (int i=1; i<=n; i++){
        if (color[i] == -1){
            if (!checkIfBipartide(adjList, color, i)) return false;
        }
    }
    return true;
}

int bfs(vector<vector<int>>& adjList, int node){
    vector<bool> visited (adjList.size(), false);
    queue<int> q;
    q.push(node);
    visited[node] = true;
    int count = 0;
    while (!q.empty()){
        int size = q.size();
        for (int i=0; i<size; i++){
            int val = q.front();
            q.pop();
            for (int j=0; j<adjList[val].size(); j++){
                int element = adjList[val][j];
                if (!visited[element]){
                    q.push(element);
                    visited[element] = true;
                }
            }
        }
        count++;
    }
    return count;
}

int getLayerBfs(vector<vector<int>>& adjList, vector<int> component){
    int depth = 0;
    for (int i=0; i<component.size(); i++){
        depth = max(depth, bfs(adjList, component[i]));
    }
    return depth;
}


int magnificentSets(int n, vector<vector<int>>& edges) {
    //Get Adjacency List
    vector<vector<int>> adjList = getAdjList(n, edges);
    // Check for Bipartideness
    if (!isBipartide(n, adjList)) return -1;
    // Do a BFS traversal to get the max layers
    int layer = 0;
    vector<bool> visited (n+1, false);
    for (int i=1; i<=n; i++){
        vector<int> component;
        if (!visited[i]){
            queue<int> q;
            q.push(i);
            component.push_back(i);
            visited[i] = true;
            while (!q.empty()){
                int val = q.front();
                q.pop();
                for (int i=0; i<adjList[val].size(); i++){
                    int element = adjList[val][i];
                    if (!visited[element]){
                        q.push(element);
                        component.push_back(element);
                        visited[element] = true;
                    }
                }
            }
        }
        layer = layer + getLayerBfs(adjList, component);
    }
    return layer;
}

//TC - O(V*(V+E));
//SC - O(N)
