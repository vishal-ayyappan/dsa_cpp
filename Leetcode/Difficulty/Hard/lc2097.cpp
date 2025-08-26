#include <bits/stdc++.h>
using namespace std;

//Valid Arrangement of Pairs

unordered_map<int, vector<int>> getAdjList(vector<vector<int>>& pairs){
    int n = pairs.size();
    unordered_map<int, vector<int>> mpp;
    for (int i=0; i<n; i++){
        int u = pairs[i][0];
        int v = pairs[i][1];
        mpp[u].push_back(v);
    }
    return mpp;
}

unordered_map<int, int> getIndegree(vector<vector<int>>& pairs){
    unordered_map<int, int> inDegree;
    int n = pairs.size();
    for (int i=0; i<n; i++){
        int v = pairs[i][1];
        inDegree[v]++;
    }
    return inDegree;
}

unordered_map<int, int> getOutDegree(vector<vector<int>>& pairs){
    unordered_map<int, int> outDegree;
    int n = pairs.size();
    for (int i=0; i<n; i++){
        int u = pairs[i][0];
        outDegree[u]++;
    }
    return outDegree;
}

unordered_set<int> getElements(vector<vector<int>>& pairs){
    unordered_set<int> s;
    int n = pairs.size();
    for (int i=0; i<n; i++){
        s.insert(pairs[i][0]);
        s.insert(pairs[i][1]);
    }
    return s;
}

void getDfs(unordered_map<int, vector<int>>& adjList, int startNode, vector<int>& eulerPath){
    while (!adjList[startNode].empty()){
        int neighbour = adjList[startNode].back();
        adjList[startNode].pop_back();
        getDfs(adjList, neighbour, eulerPath);
    }
    eulerPath.push_back(startNode);
}


vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
    //Get the adjacency List
    unordered_map<int, vector<int>> adjList = getAdjList(pairs);
    //Get the indegree
    unordered_map<int, int> inDegree = getIndegree(pairs);
    //Get the outdegree
    unordered_map<int, int> outDegree = getOutDegree(pairs);
    //Get all the nodes
    unordered_set<int> s = getElements(pairs);
    int startNode = -1;
    int endNode = -1;
    for (int node : s){
        if (outDegree[node] - inDegree[node] == 1) startNode = node;
        else if (outDegree[node] - inDegree[node] == -1) endNode = node;
    }
    //There always exists a valid pair, so either a euler path or a euler circuit exists
    //If startNode is not set, then, any node can be a start node.
    if (startNode == -1) startNode = *s.begin();
    //Do a DFS on the start node
    vector<int> eulerPath;
    getDfs(adjList, startNode, eulerPath);
    reverse(eulerPath.begin(), eulerPath.end());
    int size = eulerPath.size();
    vector<vector<int>> ans;
    for (int i=0; i<size-1; i++){
        ans.push_back({eulerPath[i], eulerPath[i+1]});
    }
    return ans;
}