#include <bits/stdc++.h>
using namespace std;

//All Paths From Source to Target
void getAllPaths(vector<vector<int>>& graph, int i, vector<int>& ds, vector<vector<int>>& ans){
    if (i == graph.size()-1){
        ds.push_back(i);
        ans.push_back(ds);
        ds.pop_back();
    }
    ds.push_back(i);
    for (int& u : graph[i]){
        getAllPaths(graph, u, ds, ans);
    }
    ds.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    //Okay, Adjacency list is given.
    //If you can reach the destination, print the ds, else do not add it in the ans
    int n = graph.size();
    vector<vector<int>> ans;
    vector<int> ds;
    //You do not need a visited array as you might visit a node multiple times
    getAllPaths(graph, 0, ds, ans);
    return ans;
}