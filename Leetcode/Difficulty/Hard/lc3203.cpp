#include <bits/stdc++.h>
using namespace std;

//Find Minimum Diameter After Merging Two Trees

//Have to merge smaller diameter tree to the larger diameter tree, so the merged tree diameter will
//be that of larger diameter tree

vector<vector<int>> getAdjList(vector<vector<int>>& edges){
    int n = edges.size();
    vector<vector<int>> adjList (n+1);
    for (int i=0; i<n; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    return adjList;
}

int getDiameter(vector<vector<int>>& adjList){
    //Do a level order traversal from any node
    int n = adjList.size();
    vector<bool> visited (n, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    int farthestNode = -1;
    while (!q.empty()){
        int size = q.size();
        for (int i=0; i<size; i++){
            int node = q.front();
            q.pop();
            farthestNode = node;
            for (int& u : adjList[node]){
                if (!visited[u]){
                    visited[u] = true;
                    q.push(u);
                }
            }
        }
    }
    //farthest node is one of the diameter, do an level order traversal from that node, to get the other end
    vector<bool> new_visited (n, false);
    int new_farthest = -1;
    q.push(farthestNode);
    int diameter = 0;
    new_visited[farthestNode] = true;
    while (!q.empty()){
        int size = q.size();
        for (int i=0; i<size; i++){
            int node = q.front();
            q.pop();
            new_farthest = node;
            for (int& u : adjList[node]){
                if (!new_visited[u]){
                    new_visited[u] = true;
                    q.push(u);
                }
            }
        }
        diameter++;
    }
    return diameter-1;
}

int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
    //Get the adjacency list
    vector<vector<int>> adjList1 = getAdjList(edges1);
    vector<vector<int>> adjList2 = getAdjList(edges2);
    //Find the diameter of the adjacency lists
    int diameter1 = getDiameter(adjList1);
    int diameter2 = getDiameter(adjList2);
    int ans = ((diameter1+1)/2 + (diameter2+1)/2 + 1);
    return max({diameter1, diameter2, ans});
}