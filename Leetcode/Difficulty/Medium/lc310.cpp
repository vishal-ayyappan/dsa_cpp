#include <bits/stdc++.h>
using namespace std;

//Minimum Height Trees
vector<vector<int>> getAdjList(int n, vector<vector<int>>& edges){
    vector<vector<int>> adjList (n);
    int size = edges.size();
    for (int i=0; i<size; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    return adjList;
}

void getPath(vector<vector<int>> adjList, int node, vector<bool>& visited2, int end2, vector<int>& ans, vector<int>& ds){
    visited2[node] = true;
    ds.push_back(node);
    if (node == end2){
        ans = ds;
        ds.pop_back();
        return;
    }
    for (int& u : adjList[node]){
        if (!visited2[u]){
            getPath(adjList, u, visited2, end2, ans, ds);
        }
    }
    ds.pop_back();
}

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    //Get adjacency list
    vector<vector<int>> adjList = getAdjList(n, edges);
    //Get the diameter
    //You start from any node and go to the last level, you would get one of the diameter.
    //Step 1
    //First level order traversal
    queue<int> q;
    vector<int> visited (n, false);
    q.push(0);
    visited[0] = true;
    int end1 = -1;
    while (!q.empty()){
        int a = q.size();
        for (int i=0; i<a; i++){
            int node = q.front(); q.pop();
            //Will store one end of the diameter
            end1 = node;
            for (int& u : adjList[node]){
                if (!visited[u]){
                    q.push(u);
                    visited[u] = true;
                }
            }
        }
    }
    //Do a level order traversal from that node. The last node will be the other end
    vector<bool> visited1 (n, false);
    int end2 = -1;
    q.push(end1);
    visited1[end1] = true;
    int lvl = 0;
    while (!q.empty()){
        int a = q.size();
        for (int i=0; i<a; i++){
            int node = q.front();
            end2 = node;
            q.pop();
            for (int& u : adjList[node]){
                if (!visited1[u]){
                    q.push(u);
                    visited1[u] = true;
                }
            }
        }
        lvl++;
    }
    //Construct the path from end1 to end2
    vector<bool> visited2 (n, false);
    vector<int> ans;
    vector<int> ds;
    getPath(adjList, end1, visited2, end2, ans, ds);
    int path_size = ans.size();
    if (path_size == 1) return {ans[0]};
    int idx = path_size/2;
    if (path_size % 2 == 0){
        return {ans[idx]};
    }
    return {ans[idx-1], ans[idx]};
}