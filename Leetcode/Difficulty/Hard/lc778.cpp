#include <bits/stdc++.h>
using namespace std;

// Swim in Rising Water

int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    //We could do Dijkstra
    //distance[i][j] --> min time to reach the i,j from 0,0.
    vector<vector<int>> time (n, vector<int> (m, INT_MAX));
    vector<int> delRow {-1, 0, 1, 0};
    vector<int> delCol {0, -1, 0, 1};
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    //You push the min time to reach the node and the node itself
    time[0][0] = 0;
    //Offset the initial value to 0.
    pq.push({time[0][0], {0,0}});
    while (!pq.empty()){
        auto item = pq.top();
        pq.pop();
        int row = item.second.first;
        int col = item.second.second;
        int prevTime = item.first;
        for (int i=0; i<4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m){
                int time_taken = max(prevTime, grid[nrow][ncol]-grid[0][0]);
                if (time_taken < time[nrow][ncol]){
                    time[nrow][ncol] = time_taken;
                    pq.push({time[nrow][ncol], {nrow, ncol}});
                }
            }
        }
    }
    return time[n-1][m-1] + grid[0][0];
}