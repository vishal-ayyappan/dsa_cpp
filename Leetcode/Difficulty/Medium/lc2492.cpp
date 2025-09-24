#include <bits/stdc++.h>
using namespace std;

//Minimum Score of a Path Between Two Cities

vector<vector<pair<int, int>>> getAdjList(int n, vector<vector<int>>& roads){
    vector<vector<pair<int, int>>> adjList (n+1);
    int size = roads.size();
    for (int i=0; i<size; i++){
        int city1 = roads[i][0];
        int city2 = roads[i][1];
        int distance = roads[i][2];
        adjList[city1].push_back({city2, distance});
        adjList[city2].push_back({city1, distance});
    }
    return adjList;
}

int minScore(int n, vector<vector<int>>& roads) {
    //Get the adjacency list
    vector<vector<pair<int, int>>> adjList = getAdjList(n, roads);
    vector<int> distances (n+1, INT_MAX);
    //Store the score and the node in the priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    distances[1] = INT_MAX;
    pq.push({distances[1], 1});
    while (!pq.empty()){
        auto item = pq.top(); pq.pop();
        int og_score = item.first;
        int og_node = item.second;
        for (auto& it : adjList[og_node]){
            int nei_node = it.first;
            int nei_score = it.second;
            int min_score_in_the_path = min(og_score, nei_score);
            if (min_score_in_the_path < distances[nei_node]){
                distances[nei_node] = min_score_in_the_path;
                pq.push({distances[nei_node], nei_node});
            }   
        }
    }
    return distances[n];
}