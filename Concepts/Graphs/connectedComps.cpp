#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> getAdjList(int V, vector<vector<int>>& edges){
    vector<vector<int>> adjList(V);
    int n = edges.size();
    for (int i=0; i<n; i++){
        int first = edges[i][0];
        int second = edges[i][1];
        adjList[first].push_back(second);
        adjList[second].push_back(first);
    }
    return adjList;
}

vector<int> getBfs(vector<vector<int>>& adjList, int idx, vector<bool>& visited){
    stack<int> st;
    vector<int> ans;
    st.push(idx);
    visited[idx] = true;
    while (!st.empty()){
        int size = st.size();
        for (int i=0; i<size; i++){
            int num = st.top();
            st.pop();
            int n = adjList[num].size();
            for (int j=0; j<n; j++){
                int number = adjList[num][j];
                if (!visited[number]){
                    visited[number] = true;
                    st.push(number);
                }
            }
            ans.push_back(num);
        }
    }
    return ans;
}

vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
    vector<vector<int>> ans;
    vector<vector<int>> adjList = getAdjList(V, edges);
    //Create a visited array
    vector<bool> visited (V, false);
    for (int i=0; i<V; i++){
        //Do a BFS
        if (!visited[i]){
            vector<int> temp = getBfs(adjList, i, visited);
            ans.push_back(temp);
        }
    }
    return ans;
}