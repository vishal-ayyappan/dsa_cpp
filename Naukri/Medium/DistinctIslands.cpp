#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> getBfs(int** arr, vector<vector<bool>>& visited, int row, int col, int n, int m){
    vector<vector<int>> ans;
    queue<pair<int,int>> q;
    q.push({row, col});
    visited[row][col] = true;
    vector<int> delRow {-1, 0, 1, 0};
    vector<int> delCol {0, -1, 0, 1};
    while (!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        ans.push_back({r, c});
        for (int i=0; i<4; i++){
            int nrow = r + delRow[i];
            int ncol = c + delCol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !visited[nrow][ncol] &&  arr[nrow][ncol] == 1){
                    visited[nrow][ncol] = true;
                    q.push({nrow, ncol});
                }
        }
    }
    return ans;
}

vector<vector<int>> getNormalized(vector<vector<int>>& temp, int row, int col){
    int n = temp.size();
    vector<vector<int>> ans;
    for (int i=0; i<n; i++){
        int n_row = row - temp[i][0];
        int n_col = col - temp[i][1];
        ans.push_back({n_row, n_col});
    }
    return ans;
}

int distinctIslands(int** arr, int n, int m){
    // int** arr --> refers to dynamic allocation of 2D array
    // pointer to a pointer to an integer.
    vector<vector<bool>> visited (n, vector<bool> (m, false));
    // Create a set
    set<vector<vector<int>>> s;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            vector<vector<int>> temp;
            if (!visited[i][j] && arr[i][j] == 1){
                temp = getBfs(arr, visited, i, j, n, m);
                vector<vector<int>> normalizedTemp = getNormalized(temp, i, j);
                s.insert(normalizedTemp);
            }
        }
    }
    return s.size();
}