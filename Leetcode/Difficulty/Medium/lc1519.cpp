#include <bits/stdc++.h>
using namespace std;

//Number of Nodes in the Sub-Tree With the Same Label

vector<vector<int>> getAdjList (int n, vector<vector<int>>& edges){
    int size = edges.size();
    vector<vector<int>> adjList (n);
    for (int i=0; i<size; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    return adjList;
}

vector<int> getSameLabel(vector<vector<int>>& adjList, string labels, int node, int parent, vector<int>& ans){
    vector<int> myLevel = vector<int> (26, 0);
    char label = labels[node];
    myLevel[label-'a'] = 1;
    for (int& u : adjList[node]){
        if (u == parent) continue;
        vector<int> child_count (26, 0);
        child_count =  getSameLabel(adjList, labels, u, node, ans);
        for (int i=0; i<26; i++){
            myLevel[i] += child_count[i];
        }
    }
    ans[node] = myLevel[label-'a'];
    return myLevel;
}

vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
    //Get adjacency list
    vector<vector<int>> adjList = getAdjList(n, edges);
    //Do a DFS 
    //Return a vector<int> 26 every time you finish a dfs
    vector<bool> visited (n, false);
    vector<int> ans (n, 0);
    getSameLabel(adjList, labels, 0, -1, ans);
    return ans;
}