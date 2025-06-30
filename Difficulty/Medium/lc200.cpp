#include <bits/stdc++.h>
using namespace std;

/* 
Do a DFS Traversal on each node
*/

void dfsTrav(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col,
    vector<int> delRow, vector<int> delCol){
        visited[row][col] = true;
        for (int i=0; i<4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if (nrow >= 0 && ncol >=0 && nrow < grid.size() && ncol < grid[0].size() &&
            grid[nrow][ncol] == '1' && !visited[nrow][ncol]){
                dfsTrav(grid, visited, nrow, ncol, delRow, delCol);
            }
        }
    }

int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int count = 0;
    vector<vector<bool>> visited (m, vector<bool> (n, false));
    vector<int> delRow {-1,0,1,0};
    vector<int> delCol {0,-1,0,1};
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (!visited[i][j]){
                dfsTrav(grid, visited, i, j, delRow, delCol);
                count++;
            }
        }
    }
    return count;
}

/*
Approach 2, BFS traversal
*/

void bfsTrav(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col){
        vector<int> delRow {-1,0,1,0};
        vector<int> delCol {0,-1,0,1};
        queue<pair<int,int>> q;
        q.push({row,col});
        visited[row][col] = true;
        while (!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i=0; i<4; i++){
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];
                if (nrow >= 0 && ncol >=0 && nrow < grid.size() && ncol < grid[0].size() &&
                grid[nrow][ncol] == '1' && !visited[nrow][ncol]){
                    q.push({nrow,ncol});
                    visited[nrow][ncol] = true;
                }
            }
        }
    }

int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int count = 0;
    vector<vector<bool>> visited (m, vector<bool> (n, false));
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (grid[i][j] == '1' && !visited[i][j]){
                bfsTrav(grid, visited, i, j);
                count++;
            }
        }
    }
    return count;
}