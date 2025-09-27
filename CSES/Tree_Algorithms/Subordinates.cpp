#include <bits/stdc++.h>
using namespace std;

//This is a Tree
//Here DP is not involved as each node has only one parent, so the subtree is just computed once. (the same recursive function is 
//not called again)

vector<vector<int>> getAdjList(int n, vector<int>& parent){
    //Get directed graph
    vector<vector<int>> adjList (n+1);
    for (int i=2; i<=n; i++){
        int u = parent[i];
        int v = i;
        adjList[u].push_back(v);
    }
    return adjList;
}

int getValues(vector<vector<int>>& adjList, vector<int>& subOrdinates, int node){
    int children = 0;
    for (int& u : adjList[node]){
        int val = 1 + getValues(adjList, subOrdinates, u);
        children += val;
    }
    return subOrdinates[node] = children;
}

vector<int> getSubOrdinates(int n, vector<int>& parent){
    //Get the adjacency list
    vector<vector<int>> adjList = getAdjList(n, parent);
    //Get children
    vector<int> subOrdinates (n+1, -1);
    getValues(adjList, subOrdinates, 1);
    subOrdinates.erase(subOrdinates.begin());
    return subOrdinates;
}

int main(){
    //You can store it as graph (Directed graph)
    int n; cin >> n;
    vector<int> parent;
    parent.push_back(0);
    parent.push_back(1); //1's boss is always 1
    for (int i=1; i<n; i++){
        int x; cin >> x;
        parent.push_back(x);
    }
    vector<int> subOrdinates = getSubOrdinates(n, parent);
    for (int& u : subOrdinates){
        cout << u << " ";
    }
    cout << endl;
}