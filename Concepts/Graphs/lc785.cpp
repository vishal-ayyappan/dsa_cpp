#include <bits/stdc++.h>
using namespace std;

/*
0/ If you can color the graph using 2 colors such that, no two adjacent nodes
have the same color, then the graph is a bipartite graph
1/ Do a BFS or a DFS having a color array, that tells which color the node is painted
*/

bool bfsBipartite(vector<vector<int>>& graph, vector<int>& color, int node){
    queue<int> q;
    q.push(node);
    color[node] = 0;
    while (!q.empty()){
        int size = q.size();
        for (int i=0; i<size; i++){
            int val = q.front();
            q.pop();
            for (int j=0; j<graph[val].size(); j++){
                int element = graph[val][j];
                if (color[element] == -1){
                    q.push(element);
                    if (color[val] == 0) color[element] = 1;
                    if (color[val] == 1) color[element] = 0;
                }
                else if (color[element] == color[val]) return false;
            } 
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color (n,-1);
    for (int i=0; i<n; i++){
        if (color[i] == -1){
            if (!bfsBipartite(graph, color, i)) return false;
        }
    }
    return true;
}


//Doing with DFS
bool dfsBipartite(vector<vector<int>>& graph, vector<int>& color, int node){
    for (int i=0; i<graph[node].size(); i++){
        int element = graph[node][i];
        if (color[element] == -1){
            color[element] = 1 - color[node];
            if (!dfsBipartite(graph, color, element)) return false;
        }
        else if (color[element] == color[node]) return false;
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color (n,-1);
    for (int i=0; i<n; i++){
        if (color[i] == -1){
            color[i] = 0;
            if (!dfsBipartite(graph, color, i)) return false;
        }
    }
    return true;
}
