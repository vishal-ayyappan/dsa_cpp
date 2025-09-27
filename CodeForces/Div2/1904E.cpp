#include <bits/stdc++.h>
using namespace std;

//Tree Queries (Not optimal)

vector<vector<int>> getAdjList(int n, vector<vector<int>>& edges){
    vector<vector<int>> adjList (n+1);
    int sz = edges.size();
    for (int i=0; i<sz; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    return adjList;
}

int getMaxPath(vector<vector<int>>& adjList, int node, unordered_map<int, bool>& marked, int parent){
    int maxi = 1;
    for (int& u : adjList[node]){
        //Do not go to the parent node
        if (u != parent){
            //If it is not marked
            if (marked.find(u) == marked.end()){
                int len = 1 + getMaxPath(adjList, u, marked, node);
                maxi = max(maxi, len);
            }
        }
    }
    return maxi;
}

void getMaxPathQuery(int n, vector<vector<int>>& edges, int nq, vector<vector<int>>& queries){
    //Get the adjacency list
    vector<vector<int>> adjList = getAdjList(n, edges);
    //Go through each query
    for (int i=0; i<nq; i++){
        unordered_map<int, bool> marked;
        for (int j=1; j<queries[i].size(); j++){
            int skip_node = queries[i][j];
            marked[skip_node] = true;
        }
        int path_len = getMaxPath(adjList, queries[i][0], marked, -1) - 1;
        cout << path_len << endl;
    }
}


//Optimal


int main(){
    int n; int nq;
    cin >> n; cin >> nq;
    vector<vector<int>> edges;
    for (int i=0; i<n-1; i++){
        int a; int b;
        cin >> a; cin >> b;
        edges.push_back({a, b});
    }
    vector<vector<int>> queries;
    for (int i=0; i<nq; i++){
        int node; cin >> node;
        int node_rem; cin >> node_rem;
        vector<int> query;
        query.push_back(node);
        for (int j=0; j<node_rem; j++){
            int miss_node; cin >> miss_node;
            query.push_back(miss_node);
        }
        queries.push_back(query);
    }
    getMaxPathQuery(n, edges, nq, queries);
    return 0;
}