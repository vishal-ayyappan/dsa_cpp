#include <bits/stdc++.h>
using namespace std;

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
    vector<int> inDegree(numCourses);
    int n = prerequisites.size();
    for (int i=0; i<n; i++){
        int first = prerequisites[i][0];
        inDegree[first]++;
    }
    return inDegree;
}

int getCount(vector<vector<int>>& adjList, vector<int>& inDegree){
    int n = inDegree.size();
    queue<int> q;
    for (int i=0; i<n; i++){
        if (inDegree[i] == 0) q.push(i);
    }
    int count = 0;
    while (!q.empty()){
        int node = q.front();
        q.pop();
        count++;
        for (int u : adjList[node]){
            inDegree[u]--;
            if (inDegree[u] == 0){
                q.push(u);
            }
        }
    }
    return count;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // prerequisites[i][j] you have to take, course j before course i
    vector<vector<int>> adjList = getAdjList(numCourses, prerequisites);
    //Now, get the indegrees.
    vector<int> inDegree = getInDegree(numCourses, prerequisites);
    //Now if this forms a DAG
    int count = getCount(adjList, inDegree);
    if (count == numCourses) return true;
    return false;
}