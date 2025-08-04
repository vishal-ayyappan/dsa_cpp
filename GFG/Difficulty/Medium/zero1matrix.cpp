#include <bits/stdc++.h>
using namespace std;

// You have to get the distance of the nearest 1 for each cell.

vector<vector<int>> getSetNodes(vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> setNodes;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (grid[i][j] == 1){
                setNodes.push_back({i,j});
            }
        }
    }
    return setNodes;
}

vector<vector<int>> getNearest(vector<vector<int>>& grid, vector<vector<int>>& setNodes, vector<vector<bool>>& visited){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> ans (n, vector<int> (m));
    int size = setNodes.size();
    int distance = 0;
    queue<pair<int, int>> q;
    for (int i=0; i<size; i++){
        int row = setNodes[i][0];
        int col = setNodes[i][1];
        q.push({row, col});
        visited[row][col] = true;
    }
    vector<int> delRow {-1, 0, 1, 0};
    vector<int> delCol {0, -1, 0, 1};
    while (!q.empty()){
        int q_size = q.size();
        for (int i=0; i<q_size; i++){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            ans[r][c] = distance;
            for (int j=0; j<4; j++){
                int nrow = r + delRow[j];
                int ncol = c + delCol[j];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !visited[nrow][ncol]){
                    q.push({nrow, ncol});
                    visited[nrow][ncol] = true;
                }
            }
        }
        distance++;
    }
    return ans;
}

vector<vector<int>> nearest(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    // Do multisource BFS to get the nearest distance
    // There is atleast one 1 on the grid, so answer always exists
    
    // 0/ Get all the indices having 1
    vector<vector<int>> setNodes = getSetNodes(grid);
    // 1/ Create a visited array
    vector<vector<bool>> visited (n, vector<bool> (m, false));
    return getNearest(grid, setNodes, visited);
}