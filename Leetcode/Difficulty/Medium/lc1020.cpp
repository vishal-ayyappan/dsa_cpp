#include <bits/stdc++.h>
using namespace std;

/*
0/ Get the boundary 1's
1/ Do a DFS traversal for all the 1's in the boundary if not visited before
2/ Iterate through the matrix, and if any element is 1 and is not visited, count those
*/

void multiDfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col,
vector<int> delRow, vector<int> delCol, int& visitedOnes){
    visited[row][col] = true;
    visitedOnes++;
    for (int i=0; i<4; i++){
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        if (nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() 
            && grid[nrow][ncol] == 1 && !visited[nrow][ncol]){
                multiDfs(grid, visited, nrow, ncol, delRow, delCol, visitedOnes);
            }
    }
}

int numEnclaves(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    //Get the boundary 1's
    vector<pair<int,int>> nodes;
    int ones = 0;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (grid[i][j] == 1){
                if (i == 0 || i == m-1) nodes.push_back({i,j});
                else{
                    if (j == 0 || j == n-1) nodes.push_back({i,j});
                }
                ones++;
            }

        }
    }
    //Multisource DFS
    vector<vector<bool>> visited (m, vector<bool> (n, false));
    vector<int> delRow {-1,0,1,0};
    vector<int> delCol {0,-1,0,1};
    int visitedOnes = 0;
    for (int i=0; i<nodes.size(); i++){
        int row = nodes[i].first;
        int col = nodes[i].second;
        if (!visited[row][col]){
            multiDfs(grid, visited, row, col, delRow, delCol, visitedOnes);
        }
    }
    return ones - visitedOnes;
}



/* 
Approach 2 (Using multisource BFS)

*/

int numEnclaves(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited (m, vector<bool> (n, false));
    queue<pair<int,int>> q;
    //Get all the 1's in the boundary
    int ones = 0;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (grid[i][j] == 1){
                if (i == 0 || j == 0 || i == m-1 || j == n-1) {
                    q.push({i,j});
                    visited[i][j] = true;
                }
                ones++;
            }
        }
    }
    vector<int> delRow {-1,0,1,0};
    vector<int> delCol {0,-1,0,1};   
    int visitedOnes = 0;  
    while (!q.empty()){
        int size = q.size();
        for (int i=0; i<size; i++){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            visitedOnes++;
            for (int j=0; j<4; j++){
                int nrow = row + delRow[j];
                int ncol = col + delCol[j];
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1 &&
                !visited[nrow][ncol]){
                    q.push({nrow, ncol});
                    visited[nrow][ncol] = true;
                }
            }
        }
    }
    return ones - visitedOnes;
}