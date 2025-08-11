#include <bits/stdc++.h>
using namespace std;

//Alien Dictionary

vector<vector<int>> getAdjList(vector<vector<int>> edges, int vertices){
    vector<vector<int>> adjList (vertices);
    int n = edges.size();
    for (int i=0; i<n; i++){
        int first = edges[i][0];
        int second = edges[i][1];
        adjList[first].push_back(second);
    }
    return adjList;
}

vector<int> getIndegree(vector<vector<int>>& edges, int vertices){
    vector<int> inDegree (vertices, 0);
    int n = edges.size();
    for (int i=0; i<n; i++){
        int first = edges[i][0];
        int second = edges[i][1];
        inDegree[second]++;
    }
    return inDegree;
}

vector<int> getAlien(vector<vector<int>>& adjList, vector<int>& inDegree, unordered_set<int>& s){
    vector<int> ans;
    int n = inDegree.size();
    queue<int> q;
    for (int i=0; i<n; i++){
        //If the character is mentioned
        if (inDegree[i] == 0 && s.find(i) != s.end()) q.push(i);
    }
    while (!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (int u : adjList[node]){
            inDegree[u]--;
            if (inDegree[u] == 0){
                q.push(u);
            }
        }
    }
    return ans;
}

string findOrder(vector<string> &words) {
    vector<vector<int>> edges;
    int n = words.size();
    unordered_set<int> s;
    for (int i=0; i<n; i++){
        for (int j=0; j<words[i].length(); j++){
            s.insert(words[i][j] - 'a');
        }
    }
    int k = s.size();
    //Get the edges
    for (int i=0; i<n-1; i++){
        string word1 = words[i];
        string word2 = words[i+1];
        int size = min(word1.length(), word2.length());
        bool didBreak = false;
        for (int j=0; j<size; j++){
            if (word1[j] != word2[j]){
                edges.push_back({word1[j]-'a', word2[j]-'a'});
                didBreak = true;
                break;
            }
        }
        if (!didBreak && word1.size() > word2.size()) return "";
    }
    //Now, get the adjacency list
    vector<vector<int>> adjList = getAdjList(edges, 26);
    vector<int> inDegree = getIndegree(edges, 26);
    vector<int> alien = getAlien(adjList, inDegree, s);
    string ans;
    if (alien.size() != k) return ans;
    for (int num : alien){
        char ch = char(num + 'a');
        ans.push_back(ch);
    }
    return ans;
}