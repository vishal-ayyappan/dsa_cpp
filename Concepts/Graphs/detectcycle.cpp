#include <bits/stdc++.h>
using namespace std;

/*
Approach (Using BFS)
0/ Do a BFS traversal and keep a parent node when you store it in the queue
1/ As BFS goes level order wise, if the visited[node] gives true to any value 
other than the parent, that means there exists a cycle
//2 When doing level order search, other than parents, no other node should have been 
visited before hand for the graph to be acyclic 
*/

vector<vector<int>> getAdjList(int V, vector<vector<int>>& edges){
    vector<vector<int>> adjList (V);
    for (int i=0; i<edges.size(); i++){
        adjList[edges[i][0]].push_back(edges[i][1]);
        adjList[edges[i][1]].push_back(edges[i][0]);
    }
    return adjList;
}

bool checkCycle(int V, vector<vector<int>>& adjList, vector<bool>& visited, int node){
    //Store the node and the parent in the queue
    queue<pair<int,int>> q;
    q.push({node,-1});
    visited[node] = true;
    while (!q.empty()){
        int size = q.size();
        for (int i=0; i<size; i++){
            auto item = q.front();
            q.pop();
            int val = item.first;
            int parent = item.second;
            for (int j=0; j<adjList[val].size(); j++){
                int element = adjList[val][j];
                if (!visited[element]){
                    q.push({element, val});
                    visited[element] = true;
                }
                else if (element != parent){
                    return true;
                }
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<vector<int>>& edges) {
    //Create adjList
    vector<vector<int>> adjList = getAdjList(V, edges);
    vector<bool> visited (V, false);
    for (int i=0; i<V; i++){
        if (!visited[i]){
            if (checkCycle(V, adjList, visited, i)) return true;
        }
    }
    return false;
}

//TC - O(V) + O(V+2E)
//SC - O(V)


/*
Approach 2 (Using DFS)
0/ If the node is already visited and if it is not parent node, then return true
*/

vector<vector<int>> getAdjList(int V, vector<vector<int>>& edges){
    vector<vector<int>> adjList (V);
    for (int i=0; i<edges.size(); i++){
        adjList[edges[i][0]].push_back(edges[i][1]);
        adjList[edges[i][1]].push_back(edges[i][0]);
    }
    return adjList;
}

bool checkCycleDfs(vector<vector<int>>& adjList, int node, vector<bool>& visited, int parent){
    visited[node] = true;
    for (int i=0; i<adjList[node].size(); i++){
        int element = adjList[node][i];
        if (!visited[element]){
            if (checkCycleDfs(adjList, element, visited, node)){
                return true;
            }
        }
        else if (parent != element) return true;
    }
    return false;

}

bool isCycle(int V, vector<vector<int>>& edges) {
    //Create adjList
    vector<vector<int>> adjList = getAdjList(V, edges);
    vector<bool> visited (V, false);
    int parent = -1;
    for (int i=0; i<V; i++){
        if (!visited[i]){
            if (checkCycleDfs(adjList, i, visited, parent)){
                return true;
            }
        }
    }
    return false;
}

//TC - O(V) + O(V+2E)
//SC - O(V)