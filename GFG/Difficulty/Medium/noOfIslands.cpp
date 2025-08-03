#include <bits/stdc++.h>
using namespace std;

// An island is either surrounded by water or the boundary of a grid and is 
// formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

void getCount(vector<vector<char>>& grid, int row, int col, vector<vector<bool>>& visited){
    int n = grid.size();
    int m = grid[0].size();
    vector<int> delRow {-1, 0, 1, 0, 1, -1, 1, -1};
    vector<int> delCol {0, -1, 0, 1, 1, 1, -1, -1};
    stack<pair<int,int>> st;
    st.push({row, col});
    visited[row][col] = true;
    while (!st.empty()){
        int size = st.size();
        for (int i=0; i<size; i++){
            int row_ = st.top().first;
            int col_ = st.top().second;
            st.pop();
            for (int j=0; j<8; j++){
                int newRow = row_ + delRow[j];
                int newCol = col_ + delCol[j];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && 
                    !visited[newRow][newCol] && grid[newRow][newCol] == 'L'){
                        st.push({newRow, newCol});
                        visited[newRow][newCol] = true;
                    }
            }
        }
    }
}


int countIslands(vector<vector<char>>& grid) {
    // 0/ Get all the ones
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited (n, vector<bool> (m, false));
    int count = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (!visited[i][j] && grid[i][j] == 'L'){
                getCount(grid, i, j, visited);
                count++;
            }
        }
    }   
    return count;
}