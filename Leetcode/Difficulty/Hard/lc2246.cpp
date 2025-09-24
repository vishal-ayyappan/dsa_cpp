#include <bits/stdc++.h>
using namespace std;

//Longest Path With Different Adjacent Characters (Good, tree-graph question!h)


vector<vector<int>> getAdjList(vector<int>& parent, int n){
    vector<vector<int>> adjList (n);
    for (int i=0; i<n; i++){
        int u = i;
        int v = parent[i];
        //If you deal with the root
        if (v == -1) continue;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    return adjList;
}

int getLongestPath(vector<vector<int>>& adjList, string s, int current, int parent, int& result){
    //You have to find the longest and the second longest branch
    int longest = 0;
    int second_longest = 0;
    for (int& child : adjList[current]){
        if (child == parent) continue;
        int path = getLongestPath(adjList, s, child, current, result);
        //When the child character equals parent character, they do not contribute to the path
        if (s[current] == s[child]) continue;
        if (path > longest){
            second_longest = longest;
            longest = path;
        }
        else if (path > second_longest){
            second_longest = path;
        }
    }
    int maxPath = longest + second_longest + 1;
    result = max(result, maxPath);
    return longest + 1;
}

int longestPath(vector<int>& parent, string s) {
    //This is similar to binary tree maximum path sum
    //Get adjacency list
    int n = parent.size();
    vector<vector<int>> adjList = getAdjList(parent, n);
    //Do a DFS traversal
    int result = 0;
    getLongestPath(adjList, s, 0, -1, result);
    return result;
}