#include <bits/stdc++.h>
using namespace std;

//Keys and Rooms
void getRooms(vector<vector<int>>& rooms, int node, vector<bool>& visited){
    visited[node] = true;
    for (int& u : rooms[node]){
        if (!visited[u]){
            getRooms(rooms, u, visited);
        }
    }
}

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    //The start node is 0
    //The adjacency list is already given
    int n = rooms.size();
    vector<bool> visited (n, false);
    getRooms(rooms, 0, visited);
    for (int i=0; i<n; i++){
        if (!visited[i]) return false;
    }
    return true;
}