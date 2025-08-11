#include <bits/stdc++.h>
using namespace std;

//Path with minimum effort

int minimumEffortPath(vector<vector<int>>& heights) {
    int n = heights.size();
    int m = heights[0].size();
    // Stores the maximum difference 2 consecutive cells in the path
    vector<vector<int>> distance (n, vector<int> (m, INT_MAX));
    // Direction of traversal
    vector<int> delRow {-1, 0, 1, 0};
    vector<int> delCol {0, -1, 0, 1};
    // Declare a min heap priority queue, that stores, the maximum absolute difference in the path
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    distance[0][0] = 0;
    pq.push({distance[0][0], {0,0}});
    while (!pq.empty()){
        auto item = pq.top();
        pq.pop();
        int value = item.first;
        auto index = item.second;
        int row = index.first;
        int col = index.second;
        int grid_val = heights[row][col];
        for (int i=0; i<4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            //Check if indexes are valid
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m){
                int new_grid_val = heights[nrow][ncol];
                int diff = abs(new_grid_val - grid_val);
                int val = max(distance[row][col], diff);
                //You need the minimum effort
                if (val < distance[nrow][ncol]){
                    distance[nrow][ncol] = val;
                    pq.push({distance[nrow][ncol], {nrow, ncol}});
                }
            }
        }
    }
    return distance[n-1][m-1];
}