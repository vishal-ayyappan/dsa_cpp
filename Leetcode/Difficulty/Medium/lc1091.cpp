#include <bits/stdc++.h>
using namespace std;

//Shortest Path Binary Matrix (Using shortest path Djikistra Algo) 
// Can be done using simple bfs algo too

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    //Explore all the nodes with zero value (including the diagonal), and find the shortest path
    //Each move will result in +1 (all the weights here are 1)
    int n = grid.size();
    vector<vector<int>> distance (n, vector<int> (n, INT_MAX));
    // source is [0][0] and destination is [n-1][n-1], both should be 0
    if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
    // Store the distance and the node
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    // To traverse the grid and find all the possibilities
    vector<int> delRow {-1, 0, 1, 0, -1, -1, 1, 1};
    vector<int> delCol {0, -1, 0, 1, -1, 1, -1, 1};
    distance[0][0] = 0;
    pq.push({distance[0][0], {0,0}});
    while (!pq.empty()){
        auto item = pq.top();
        pq.pop();
        int wt = item.first;
        auto index = item.second;
        int row = index.first;
        int column = index.second;
        for (int i=0; i<8; i++){
            int nrow = row + delRow[i];
            int ncol = column + delCol[i];
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < n){
                if (grid[nrow][ncol] == 0){
                    int weight = distance[row][column] + 1;
                    if (weight < distance[row][column]){
                        distance[nrow][ncol] = weight;
                        pq.push({distance[nrow][ncol], {nrow, ncol}});
                    }
                }
            }
        }
    }
    if (distance[n-1][n-1] == INT_MAX) return -1;
    return distance[n-1][n-1]+1;
}