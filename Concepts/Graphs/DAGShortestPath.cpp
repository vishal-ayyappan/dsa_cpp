#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> getAdjList(int V, vector<vector<int>>& edges){
    int n = edges.size();
    vector<vector<pair<int, int>>> adjList (V);
    for (int i=0; i<n; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adjList[u].push_back({v, wt});
    }
    return adjList;
}

vector<int> getInDegree(int V, vector<vector<int>>& edges){
    vector<int> inDegree(V);
    int n = edges.size();
    for (int i=0; i<n; i++){
        int v = edges[i][1];
        inDegree[v]++;
    }
    return inDegree;
}

vector<int> getTopo(vector<vector<pair<int, int>>>& adjList, vector<int>& inDegree){
    int n = inDegree.size();
    vector<int> sorted;
    //Push all the indegree 0 nodes, to the queue; they are the ones that appear first
    queue<int> q;
    for (int i=0; i<n; i++){
        if (inDegree[i] == 0) q.push(i);
    }
    while (!q.empty()){
        int node = q.front();
        q.pop();
        sorted.push_back(node);
        for (auto& u : adjList[node]){
            int n_node = u.first;
            inDegree[n_node]--;
            if (inDegree[n_node] == 0){
                q.push(n_node);
            }
        }
    }
    return sorted;
}

vector<int> getCount(vector<int>& topo, vector<vector<pair<int, int>>>& adjList){
    //You have to start from 0, iterate until you get 0;
    int i = 0;
    int n = topo.size();
    vector<int> distance (n, INT_MAX);
    distance[0] = 0;
    //You start from the source
    while (i < n){
        int node = topo[i];
        if (distance[node] != INT_MAX){
            for (auto &u : adjList[node]){
                int n_node = u.first;
                int wt = u.second;
                int og_distance = distance[node];
                int new_distance = og_distance + wt;
                distance[n_node] = min(distance[n_node], new_distance);
            }
        }
        i++;
    }
    return distance;
}

//It is given a DAG, so we can use both bfs and dfs
vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
    //Get the adjacency list
    vector<vector<pair<int, int>>> adjList = getAdjList(V, edges);
    //Do the topological sorting of the list, using BFS/DFS
    vector<int> inDegree = getInDegree(V, edges);
    vector<int> topo = getTopo(adjList, inDegree);
    //Get the count
    vector<int> distance = getCount(topo, adjList);
    int n = distance.size();
    for (int i=0; i<n; i++){
        if (distance[i] == INT_MAX) distance[i] = -1;
    }
    return distance;
}