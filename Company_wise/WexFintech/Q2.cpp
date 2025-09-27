#include <bits/stdc++.h>
using namespace std;

//Max Happiness (This is not the optimal approach)
//Optimal approach includes (High level Decomposition + Segment Trees) ~ 2200 rated cf

vector<vector<int>> getAdjList(int n, vector<vector<int>>& edges){
    //1 based indexing
    vector<vector<int>> adjList (n+1);
    //Size of the edge n-1
    for (int i=0; i<n-1; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    return adjList;
}

//DFS + Backtracking to get the path
void getWay(vector<vector<int>>& adjList, int node, int end, vector<int>& path, vector<int>& ds, vector<bool>& visited){
    visited[node] = true;
    ds.push_back(node);
    if (node == end){
        path = ds;
        ds.pop_back();
        return;
    }
    for (int& u : adjList[node]){
        if (!visited[u]){
            getWay(adjList, u, end, path, ds, visited);
        }
    }
    ds.pop_back();
    visited[node] = false;
}

vector<int> getPath(vector<vector<int>>& adjList, int start, int end, int n){
    vector<int> path;
    vector<bool> visited (n+1, false);
    vector<int> ds;
    getWay(adjList, start, end, path, ds, visited);
    return path;
}

int getMaxSum(vector<int>& path, vector<int>& reward){
    int sz = path.size();
    int sum = 0;
    int maxSum = INT_MIN;
    for (int i=0; i<sz; i++){
        int node = path[i];
        sum += reward[node-1];
        maxSum = max(maxSum, sum);
        if (sum < 0) sum = 0;
    }
    return maxSum;
}

void getMaxHappiness(int n, vector<vector<int>>& edges, vector<int>& reward, int nq, vector<vector<int>>& queries){
    //Get the adjacency list
    vector<vector<int>> adjList = getAdjList(n, edges);
    int maxi = INT_MIN;
    //For each query get the path
    for (int i=0; i<nq; i++){
        int start = queries[i][0];
        int end = queries[i][1];
        //Get the path
        vector<int> path = getPath(adjList, start, end, n);
        //Get the maximum sum of subarray
        int maxSum = getMaxSum(path, reward);
        maxi = max(maxi, maxSum);
    }
    cout << maxi << endl;
}

int main(){
    cout << "No of test cases" << endl;
    int t; cin >> t;
    while (t > 0){
        //no of nodes
        cout << "Enter no of nodes" << endl;
        int n; cin >> n;
        //Get the edges
        cout << "Enter " << n-1 << " edges" << endl;
        vector<vector<int>> edges;
        for (int i=0; i<n-1; i++){
            int u; cin >> u;
            int v; cin >> v;
            edges.push_back({u, v});
        }
        cout << "Enter the reward for each node" << endl;
        //Get the reward
        vector<int> reward;
        for (int i=0; i<n; i++){
            int rw; cin >> rw;
            reward.push_back(rw);
        }
        //Get the number of queries
        cout << "Enter the no of queries " << endl;
        int nq; cin >> nq;
        //Get the queries
        cout << "Enter " << nq << " queries" << endl;
        vector<vector<int>> queries;
        for (int i=0; i<nq; i++){
            int s; cin >> s;
            int e; cin >> e;
            queries.push_back({s, e});
        }
        getMaxHappiness(n, edges, reward, nq, queries);
        t--;
    }
}