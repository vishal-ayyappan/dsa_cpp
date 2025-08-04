#include <bits/stdc++.h>
using namespace std;

//Capture Regions

// Using Multisource BFS
vector<vector<int>> getSetNodes(vector<vector<char>> &s, int n, int m){
    vector<vector<int>> setNodes;
    // Go through the first and the last column
    for (int i=0; i<n; i++){
        if (s[i][0] == 'O') setNodes.push_back({i, 0});
        if (s[i][m-1] == 'O') setNodes.push_back({i, m-1});
    }
    // Go theough the first and last row
    for (int j=0; j<m; j++){
        if (s[0][j] == 'O') setNodes.push_back({0, j});
        if (s[n-1][j] == 'O') setNodes.push_back({n-1, j});
    }
    return setNodes;
}


void getRegion(vector<vector<char>> &s, vector<vector<int>>& setNodes, vector<vector<bool>>& visited){
    int n = s.size();
    int m = s[0].size();
    vector<int> delRow {-1, 0, 1, 0};
    vector<int> delCol {0, -1, 0, 1};
    queue<pair<int, int>> q;
    int size = setNodes.size();
    for (int i=0; i<size; i++){
        int row = setNodes[i][0];
        int col = setNodes[i][1];
        visited[row][col] = true;
        q.push({row, col});
    }
    while (!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i=0; i<4; i++){
            int nrow = r + delRow[i];
            int ncol = c + delCol[i];
            if (nrow >= 1 && nrow < n-1 && ncol >= 1 && ncol < m-1 &&
                !visited[nrow][ncol] && s[nrow][ncol] == 'O'){
                    visited[nrow][ncol] = true;
                    q.push({nrow, ncol});
                }
        }
    }
}


vector<vector<char>> captureRegion(vector<vector<char>> &s, int n, int m) {
    vector<vector<bool>> visited (n, vector<bool> (m, false));
    vector<vector<int>> setNodes = getSetNodes(s, n, m);
    //Do multisorce BFS/DFS on this
    getRegion(s, setNodes, visited);
    vector<vector<char>> new_s = s;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (new_s[i][j] == 'O' && !visited[i][j]){
                new_s[i][j] = 'X';
            }
        }
    }
    return new_s;
}


//Using multisource dfs


void getRegion_dfs(vector<vector<char>> &s, int row, int col, vector<vector<bool>>& visited, vector<int>& delRow, 
    vector<int>& delCol){
    visited[row][col] = true;
    for (int i=0; i<4; i++){
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        if (nrow >= 1 && nrow < s.size()-1 && ncol >= 1 && ncol < s[0].size()-1 &&
            !visited[nrow][ncol] && s[nrow][ncol] == 'O'){
                getRegion_dfs(s, nrow, ncol, visited, delRow, delCol);
        }
    }
}

vector<vector<char>> captureRegion(vector<vector<char>> &s, int n, int m) {
    vector<vector<bool>> visited (n, vector<bool> (m, false));
    vector<vector<int>> setNodes = getSetNodes(s, n, m);
    int size = setNodes.size();
    //Do multisorce BFS/DFS on this
    vector<int> delRow {-1, 0, 1, 0};
    vector<int> delCol {0, -1, 0, 1};
    for (int i=0; i<size; i++){
        int row = setNodes[i][0];
        int col = setNodes[i][1];
        getRegion_dfs(s, row, col, visited, delRow, delCol);
    }
    vector<vector<char>> new_s = s;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (new_s[i][j] == 'O' && !visited[i][j]){
                new_s[i][j] = 'X';
            }
        }
    }
    return new_s;
}
