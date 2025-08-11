#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> getAdjList(int n, vector < pair < int, int >> & edges){
    vector<vector<int>> adjList (n+1);
    int size = edges.size();
    for (int i=0; i<size; i++){
        int first = edges[i].first;
        int second = edges[i].second;
        adjList[first].push_back(second);
    }
    return adjList;
}

vector<int> getInDegree(int n, vector < pair < int, int >> & edges){
    vector<int> inDegree (n+1);
    int size = edges.size();
    for (int i=0; i<size; i++){
        int second = edges[i].second;
        inDegree[second]++;
    }
    return inDegree;
}

int getSorted(vector<vector<int>>& adjList, vector<int>& inDegree, int n){
    //Put all the nodes, that have indegree 0 in the queue, as there are no indegree for those node, 
    //they happen to be the first to appear.
    int count = 0;
    queue<int> q;
    for (int i=1; i<=n; i++){
        if (inDegree[i] == 0) q.push(i);
    }
    //You only store the node with indegree 0 in the queue.
    while (!q.empty()){
        int node = q.front();
        q.pop();
        count++;
        for (int u : adjList[node]){
            inDegree[u]--;
            if (inDegree[u] == 0) q.push(u);
        }
    }
    return count;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    //Get the adjacency list
    vector<vector<int>> adjList = getAdjList(n+1, edges);
    //Get the indegree array
    vector<int> inDegree = getInDegree(n+1, edges);
    //Do multisource bfs with all nodes that has indegree 0
    int sorted_count = getSorted(adjList, inDegree, n);
    //Check the size of the final array.
    if (sorted_count == n) return 0;
    return 1;
}