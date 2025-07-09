#include <bits/stdc++.h>
using namespace std;

/*
Do multisource DFS with nodes x, and whenever you encounter 0, visited = true
Also, avoid the edges (DFS)
*/

void getMultiDfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int row, int col, 
    vector<int> delRow, vector<int> delCol){
    visited[row][col] = true;
    for (int i=0; i<4; i++){
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        if (nrow >= 1 && nrow < board.size()-1 && ncol >= 1 && ncol < board[0].size()-1
        && board[nrow][ncol] == 'O' && !visited[nrow][ncol]){
            getMultiDfs(board, visited, nrow, ncol, delRow, delCol);
        }
    }
}

void solve(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();
    vector<pair<int,int>> nodes;
    for (int i=0; i<n; i++){
        if (board[0][i] == 'O') nodes.push_back({0,i});
        if (board[m-1][i] == 'O') nodes.push_back({m-1,i});
    }
    for (int i=1; i<m-1; i++){
        if (board[i][0] == 'O') nodes.push_back({i,0});
        if (board[i][n-1] == 'O') nodes.push_back({i,n-1});    
    }
    // Do a multisource DFS checking 
    vector<vector<bool>> visited (m, vector<bool> (n,false));
    vector<int> delRow {-1,0,1,0};
    vector<int> delCol {0,-1,0,1};
    for (int i=0; i<nodes.size(); i++){
        getMultiDfs(board, visited, nodes[i].first, nodes[i].second, delRow, delCol);
    }
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (board[i][j] == 'O' && !visited[i][j]){
                board[i][j] = 'X';
            }
        }
    }
}

//TC - O(M*N)
//SC - O(M*N)


