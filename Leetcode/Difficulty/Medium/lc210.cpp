#include <bits/stdc++.h>
using namespace std;

//Course Schedule II

vector<vector<int>> getAdjList(int numCourses, vector<vector<int>>& prerequisites){
    vector<vector<int>> adjList (numCourses);
    int n = prerequisites.size();
    for (int i=0; i<n; i++){
        int first = prerequisites[i][0];
        int second = prerequisites[i][1];
        adjList[second].push_back(first);
    }
    return adjList;
}

vector<int> getInDegree(int numCourses, vector<vector<int>>& prerequisites){
    vector<int> inDegree (numCourses);
    int n = prerequisites.size();
    for (int i=0; i<n; i++){
        int first = prerequisites[i][0];
        inDegree[first]++;
    }
    return inDegree;
}

vector<int> getSorted(vector<vector<int>>& adjList, vector<int>& inDegree){
    int n = inDegree.size();
    vector<int> sorted;
    queue<int> q;
    for (int i=0; i<n; i++){
        if (inDegree[i] == 0){
            q.push(i);
        }
    }
    while (!q.empty()){
        int node = q.front();
        q.pop();
        sorted.push_back(node);
        for (int u : adjList[node]){
            inDegree[u]--;
            if (inDegree[u] == 0) q.push(u);
        }
    }
    return sorted;
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    //Here, you have to print the order
    vector<vector<int>> adjList = getAdjList(numCourses, prerequisites);
    vector<int> inDegree = getInDegree(numCourses, prerequisites);
    vector<int> sorted = getSorted(adjList, inDegree);
    if (sorted.size() == numCourses) return sorted;
    return {};
}