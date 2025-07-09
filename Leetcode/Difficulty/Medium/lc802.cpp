#include <bits/stdc++.h>
using namespace std;

/*
//Adjacency List is given
//Do the checking for a cycle in the directed graph, if there is a cycle
then pathVisited and visited will have 1. 
//At the end after the nodes are visited, iterate through the pathVisited and whichever
node has false, return those indexes in the vector
*/

bool isCyclic(vector<vector<int>>& graph, int node, vector<bool>& visited, vector<bool>& pathVisited){
    visited[node] = true;
    pathVisited[node] = true;
    for (int i=0; i<graph[node].size(); i++){
        int element = graph[node][i];
        if (!visited[element]){
            if (isCyclic(graph, element, visited, pathVisited)) return true;
        }
        else if (pathVisited[element]) return true;
    }
    pathVisited[node] = false;
    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    vector<int> ans;
    int n = graph.size();
    vector<bool> visited (n, false);
    vector<bool> pathVisited (n, false);
    for (int i=0; i<n; i++){
        if (!visited[i]){
            isCyclic(graph, i, visited, pathVisited);
        }
    }
    for (int i=0; i<n; i++){
        if (!pathVisited[i]){
            ans.push_back(i);
        }
    }
    return ans;
}


//One more solution
//You can have a check array

bool getCheck(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& check, 
    vector<bool>& pathVisited, int node){
    visited[node] = true;
    pathVisited[node] = true;
    for (int i=0; i<graph[node].size(); i++){
        int element = graph[node][i];
        if (!visited[element]){
            if (getCheck(graph, visited, check, pathVisited, element)) return true;
        }
        else if (pathVisited[element]) return true;
    }
    check[node] = true;
    pathVisited[node] = false;
    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    vector<int> ans;
    int n = graph.size();
    vector<bool> visited (n, false);
    vector<bool> check (n, false);
    vector<bool> pathVisited (n, false);
    for (int i=0; i<n; i++){
        if (!visited[i]){
            getCheck(graph, visited, check, pathVisited, i);
        }
    }
    for (int i=0; i<n; i++){
        if (check[i] == true){
            ans.push_back(i);
        }
    }
    return ans;
}