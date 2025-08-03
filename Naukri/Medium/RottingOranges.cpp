#include <bits/stdc++.h>
using namespace std;

// Rotting Oranges

vector<vector<int>> getRotten(vector<vector<int>>& grid){
    vector<vector<int>> rotten;
    int n = grid.size();
    int m = grid[0].size();
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (grid[i][j] == 2){
                rotten.push_back({i,j});
            }
        }
    }
    return rotten;
}

int getBfs(vector<vector<int>>& grid, vector<vector<int>>& rotten, vector<vector<bool>>& visited){
    int row_size = grid.size();
    int col_size = grid[0].size();
    //We need minimum time that is why we use BFS traversal, you can track time taken
    int n = rotten.size();
    queue<pair<int,int>> q;
    for (int i=0; i<n; i++){
        //Put all the rotten indices in the stack
        int row = rotten[i][0];
        int col = rotten[i][1];
        visited[row][col] = true;
        q.push({row, col});
    }
    int count = 0;
    vector<int> delRow {-1, 0, 1, 0};
    vector<int> delCol {0, -1, 0, 1};
    while (!q.empty()){
        int size = q.size();
        for (int i=0; i<size; i++){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int j=0; j<4; j++){
                int nrow = r + delRow[j];
                int ncol = c + delCol[j];
                if (nrow >= 0 && ncol >= 0 && nrow < row_size && ncol < col_size && 
                    !visited[nrow][ncol] && grid[nrow][ncol] == 1){
                        // You can avoid visited matrix and directly modify the array, but that is not best practice.
                        q.push({nrow, ncol});
                        visited[nrow][ncol] = true;
                    }
            }
        }
        count++;
    }
    return count;
}

int rottenOranges(vector<vector<int>>& grid) {
    //You can do multisource bfs and do inplace swapping
    //I dont think we need a visited array
    int n = grid.size();
    int m = grid[0].size();
    //Get all the indices where 2 is present
    vector<vector<int>> rotten = getRotten(grid);
    vector<vector<bool>> visited (n, vector<bool> (m, false));
    // When there are no rotten oranges
    if (rotten.size() == 0) return -1;
    //Do Multisource dfs traversal to get the minimum time
    int count = getBfs(grid, rotten, visited);
    //Check if there exists a 1
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (grid[i][j] == 1 && !visited[i][j]) return -1; 
        }
    }
    return count-1;
}